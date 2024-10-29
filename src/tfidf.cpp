#include "include/tfidf.hpp"

using namespace std;

// Função auxiliar para mesclar dois subvetores de pares (docID, relevância)
void merge(vector<pair<int, double>>& vec, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<int, double>> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = vec[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = vec[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if (L[i].second >= R[j].second){
            vec[k] = L[i];
            ++i;
        } else{
            vec[k] = R[j];
            ++j;
        }
        ++k;
    }

    while(i < n1){
        vec[k] = L[i];
        ++i;
        ++k;
    }

    while(j < n2){
        vec[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<pair<int, double>>& vec, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}

TFIDFmap calcTFIDF(const vector<vector<string>>& documentos){
    TFIDFmap tfidf;
    int numDocs = documentos.size();

    // Contar a frequência dos termos por documento
    unordered_map<string, vector<int>> termoFrequencia;
    for(int docID = 0; docID < numDocs; ++docID){
        for(const auto& termo : documentos[docID]){
            if(termoFrequencia[termo].size() < numDocs){
                termoFrequencia[termo].resize(numDocs, 0);
            }
            termoFrequencia[termo][docID]++;
        }
    }

    // Calcular o IDF para cada termo
    unordered_map<string, double> idf;
    for(const auto& [termo, freqDoc] : termoFrequencia) {
        int docsTermo = 0;
        for(int freq : freqDoc){
            if(freq > 0) docsTermo++;
        }
        // Usar log1p para evitar resultados negativos ou inconsistentes
        idf[termo] = log1p(static_cast<double>(numDocs) / (1 + docsTermo));
    }

    // Calcular o TF-IDF para cada termo em cada documento
    for(const auto& [termo, freqDoc] : termoFrequencia){
        for(int docID = 0; docID < numDocs; ++docID){
            double tf = static_cast<double>(freqDoc[docID]) / static_cast<double>(documentos[docID].size());
            tfidf[termo][docID] = tf * idf[termo];
        }
    }

    return tfidf;
}

void ranquearDocsTFIDF(const string& frase, const TFIDFmap& tfidf){
    istringstream stream(frase);
    string termo;
    unordered_map<int, double> relevancia;

    // Calcular a relevância para cada documento
    while(stream >> termo){
        if(tfidf.find(termo) != tfidf.end()){
            for(const auto& [docID, peso] : tfidf.at(termo)){
                relevancia[docID] += peso;
            }
        }
    }

    vector<pair<int, double>> ranking(relevancia.begin(), relevancia.end());

    mergeSort(ranking, 0, ranking.size() - 1);

    // Exibir o ranking dos documentos com formatação adequada
    cout << fixed << setprecision(6);  
    cout << "\nRanqueamento dos Documentos para a Frase: \"" << frase << "\"" << endl;
    for(const auto& [docID, score] : ranking){
        cout << "Documento " << docID + 1 << " - Relevância: " << score << endl;
    }
    cout << "---" << endl;
}
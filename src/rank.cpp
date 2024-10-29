#include "include/rank.hpp"

void merge(vector<tuple<int, string, int>>& vec, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<tuple<int, string, int>> L(n1), R(n2);

    for(int i = 0; i < n1; ++i)
        L[i] = vec[left + i];
    for (int j = 0; j <n2; ++j)
        R[j] = vec[mid + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = left; 

    while(i < n1 && j < n2){
        if(get<2>(L[i]) >= get<2>(R[j])){
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

void mergeSort(vector<tuple<int, string, int>>& vec, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}

void ranquearDocsFrequencia(const string& frase, const vector<vector<string>>& documentos){
    istringstream stream(frase);
    vector<string> termosFrase;
    string termo;

    while(stream >> termo){
        termosFrase.push_back(termo);
    }

    vector<tuple<int, string, int>> ranking;

    for(size_t i = 0; i < documentos.size(); ++i){
        string melhorTermo;
        int maiorFrequencia = 0;

        for(const auto& termo : termosFrase) {
            int freq = count(documentos[i].begin(), documentos[i].end(), termo);
            if(freq > maiorFrequencia){
                maiorFrequencia = freq;
                melhorTermo = termo;
            }
        }

        ranking.emplace_back(i + 1, melhorTermo, maiorFrequencia);
    }

    mergeSort(ranking, 0, ranking.size() - 1);

    cout << "\nRanqueamento dos Documentos para a Frase: \"" << frase << "\"" << endl;
    for (const auto& [docID, termo, freq] : ranking){
        cout << "Documento " << docID << "\" - Frequência: " << freq << endl;
    }
    cout << "---" << endl;
}
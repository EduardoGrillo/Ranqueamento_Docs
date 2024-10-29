#include "include/print.hpp"

using namespace std;

void output() {
    vector<vector<string>> documentos = lerDocumentos("src/dataset/input/");
    vector<string> frases = lerFrasesDePesquisa("src/dataset/frases.txt");
    unordered_set<string> stopwords = lerStopwords("src/dataset/stopwords.txt");

    TFIDFmap tfidf = calcTFIDF(documentos);

    cout << "\nRanqueando documentos com TF-IDF para cada frase:" << endl;
    for(const auto& frase : frases){
        ranquearDocsTFIDF(frase, tfidf);
    }
}

    #include "include/io.hpp"

    // Função para fazer a leitura de frases de pesquisa
    vector<string> lerFrasesDePesquisa(const string& caminhoFrases){
        ifstream arquivo(caminhoFrases);
        vector<string> frases;
        string linha;

        while(getline(arquivo, linha)){
            frases.push_back(linha);
        }
        
        return frases;
    }

    // Função para ler documentos da pasta corretamente
    vector<vector<string>> lerDocumentos(const string& caminhoPasta){
        vector<vector<string>> documentos;

        // Iterar pelos arquivos do diretório
        for(const auto& entrada : fs::directory_iterator(caminhoPasta)){
            if(fs::is_regular_file(entrada)) {  // Verifica se é um arquivo
                ifstream arquivo(entrada.path());
                if(!arquivo){
                    cerr << "Erro ao abrir o arquivo: " << entrada.path() << endl;
                    continue;
                }

                string palavra;
                vector<string> documento;
                while(arquivo >> palavra) {
                    documento.push_back(palavra);
                }
                documentos.push_back(documento);
            }
        }

        return documentos;
    }

    // Função para fazer a leitura das stopwords
    unordered_set<string> lerStopwords(const string& caminhoStopwords){
        ifstream arquivo(caminhoStopwords);
        unordered_set<string> stopwords;
        string palavra;

        while(arquivo >> palavra){
            stopwords.insert(palavra);
        }

        return stopwords;
    }

    // Função para deixar a palavra minúscula e remover pontuacoes
    string corrigirPalavra(const string& palavra){
        string correcao;

        for(char c : palavra){
            if(isalpha(c)){
                correcao += tolower(c);
            }
        }

        return correcao;
    }

    // Função para normalizar os documentos
    void normalizarDocumentos(vector<vector<string>>& documentos, const unordered_set<string>& stopwords){
        for(auto& documento : documentos){
            for(auto& palavra : documento){
                palavra = corrigirPalavra(palavra);
            }

            documento.erase(remove_if(documento.begin(), documento.end(),
                [&stopwords](const string& palavra) {
                    return stopwords.find(palavra) != stopwords.end();
                }), documento.end());
        }
    }
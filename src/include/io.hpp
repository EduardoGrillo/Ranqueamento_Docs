#ifndef IO_HPP
#define IO_HPP

#include <vector>
#include <string> 
#include <unordered_set>

#include <fstream>
#include <sstream>
#include <iostream>

#include <algorithm>
#include <filesystem>
#include <cctype> 

using namespace std;
namespace fs = std::filesystem;

vector<string> lerFrasesDePesquisa(const string& caminhoFrases);
vector<vector<string>> lerDocumentos(const string& caminhoPasta);
unordered_set<string> lerStopwords(const string& caminhoStopwords);
void normalizarDocumentos(vector<vector<string>>& documentos, const unordered_set<string>& stopwords);

#endif
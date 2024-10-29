#ifndef TFIDF_HPP
#define TFIDF_HPP

#include <cmath>   
#include <algorithm> 
#include <iostream> 
#include <sstream>

#include <iomanip> 
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

using TFIDFmap = unordered_map<string, unordered_map<int, double>>;

TFIDFmap calcTFIDF(const vector<vector<string>>& documentos);
void ranquearDocsTFIDF(const string& frase, const TFIDFmap& tfidf);

void merge(vector<tuple<int, string, int>>& vec, int left, int mid, int right);
void mergeSort(vector<tuple<int, string, int>>& vec, int left, int right);

#endif
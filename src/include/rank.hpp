#ifndef RANK_HPP
#define RANK_HPP

#include <iostream>
#include <sstream>
#include <algorithm>

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void ranquearDocsFrequencia(const string& frase, const vector<vector<string>>& documentos);

void merge(vector<tuple<int, string, int>>& vec, int left, int mid, int right);
void mergeSort(vector<tuple<int, string, int>>& vec, int left, int right);

#endif
#ifndef TRIE_HPP
#define TRIE_HPP


void trie_sort(std::vector <int> v);


void selection_sort(std::vector<int>& v);


void stableSort(std::vector<int>& v);


void sort_insertion (std::vector<int>& v);


void bubbleSort(std::vector<int>& v);


void quicksort_det_rec(std::vector<int>& v, int left, int right);


static void quicksort_det_rec(std::vector<int>& v, int left, int right);


static void quicksort_rand_rec(std::vector<int>& v, int left, int right);


void benchmark(void (*tri_func)(std::vector<int>&), const std::string &nom, int n, int type);

#endif 
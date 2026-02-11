#ifndef TRIE_HPP
#define TRIE_HPP
#include <vector>
#include <string>

// Tris individuels
void selection_sort(std::vector<int>& v);
void bubbleSort(std::vector<int>& v);
void sort_insertion(std::vector<int>& v);
void stableSort(std::vector<int>& v);
void quicksort_det(std::vector<int>& v);
void quicksort_rand(std::vector<int>& v);

// ← AJOUTEZ CETTE LIGNE ! C'est ça qui manque !
void tri_sort(std::vector<int>& v);

// Création des tableaux
std::vector<int> creattab(int n, int type);

#endif
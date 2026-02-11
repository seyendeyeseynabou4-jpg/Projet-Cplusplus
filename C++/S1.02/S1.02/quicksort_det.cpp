#include <iostream>
#include <vector>
#include <algorithm> // std::swap
#include "trie.hpp"

// Fonction récursive interne
static void quicksort_det_rec(std::vector<int>& v, int left, int right) {
    if (left >= right) return;

    int pivot = v[left];      // pivot déterministe
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while (i <= right && v[i] <= pivot) i++;
        while (v[j] > pivot) j--;
        if (i < j) std::swap(v[i], v[j]);
    }

    std::swap(v[left], v[j]); // placer le pivot

    quicksort_det_rec(v, left, j - 1);
    quicksort_det_rec(v, j + 1, right);
}

// Fonction appelée depuis main
void quicksort_deterministe(std::vector<int>& v) {
    if (!v.empty())
        quicksort_det_rec(v, 0, v.size() - 1);
}

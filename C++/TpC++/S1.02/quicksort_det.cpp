#include <iostream>
#include <vector>
#include <algorithm> 
#include "trie.hpp"



static void quicksort_det_rec(std::vector<int>& v, int left, int right) {
    if (left >= right) return;

    int pivot = v[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (v[j] <= pivot) {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    std::swap(v[i], v[right]);

    quicksort_det_rec(v, left, i - 1);
    quicksort_det_rec(v, i + 1, right);
}

void quicksort_det(std::vector<int>& v) {
    if (!v.empty())
        quicksort_det_rec(v, 0, v.size() - 1);
}

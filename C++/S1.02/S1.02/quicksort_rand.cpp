#include <vector>
#include <algorithm> // std::swap
#include <cstdlib>   // rand()
#include "trie.hpp"
static void quicksort_rand_rec(std::vector<int>& v, int left, int right) {
    if (left >= right) return;

    // Pivot aléatoire
    int pivot_index = left + rand() % (right - left + 1);
    std::swap(v[left], v[pivot_index]);

    int pivot = v[left];
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while (i <= right && v[i] <= pivot) i++;
        while (v[j] > pivot) j--;
        if (i < j) std::swap(v[i], v[j]);
    }

    std::swap(v[left], v[j]);

    quicksort_rand_rec(v, left, j - 1);
    quicksort_rand_rec(v, j + 1, right);
}

void quicksort_random(std::vector<int>& v) {
    if (!v.empty())
        quicksort_rand_rec(v, 0, v.size() - 1);
}

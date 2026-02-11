#include <vector>
#include <algorithm> // std::swap
#include <cstdlib>   // rand()
#include "trie.hpp"

static void quicksort_rand_rec(std::vector<int>& v, int left, int right) {
    if (left >= right) return;

    int pivotIndex = left + rand() % (right - left + 1);
    std::swap(v[pivotIndex], v[right]);

    int pivot = v[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (v[j] <= pivot) {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    std::swap(v[i], v[right]);

    quicksort_rand_rec(v, left, i - 1);
    quicksort_rand_rec(v, i + 1, right);
}

void quicksort_rand(std::vector<int>& v) {
    if (!v.empty())
        quicksort_rand_rec(v, 0, v.size() - 1);
}

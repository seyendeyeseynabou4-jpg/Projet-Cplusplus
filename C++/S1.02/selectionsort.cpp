#include <vector>
#include <algorithm> // Pour std::swap

void selectionSort(std::vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(v[i], v[min_idx]); // Échanger l'élément courant avec l'élément le plus petit
    }
}

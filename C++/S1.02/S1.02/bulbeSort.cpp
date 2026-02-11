#include <vector>

void bubbleSort(std::vector<int>& v) {
    int n = v.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; i++) {
            if (v[i - 1] > v[i]) {
                std::swap(v[i - 1], v[i]);
                swapped = true;
            }
        }
        n--; // Chaque passage place un élément en fin de tableau
    } while (swapped);
}

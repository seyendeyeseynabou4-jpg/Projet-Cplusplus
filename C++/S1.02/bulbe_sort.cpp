#include <vector>

void bubbleSort(std::vector<int>& v) {
    int n = v.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; i++) {
            if (v[i - 1] > v[i]) {
                std::swap(v[i - 1], v[i]); // Échanger les éléments adjacents
                swapped = true;
            }
        }
        n--; // Réduire la taille de l'intervalle, car les derniers éléments sont déjà triés
    } while (swapped);
}

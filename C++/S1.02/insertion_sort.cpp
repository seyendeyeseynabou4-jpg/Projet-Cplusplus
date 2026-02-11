#include <vector>

void insertionSort(std::vector<int>& v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j]; // Déplacer les éléments plus grands d'une position à droite
            j--;
        }
        v[j + 1] = key; // Placer la clé à sa position correcte
    }
}

#include <vector>

void quickSort(std::vector<int>& v, int low, int high) {
    if (low < high) {
        int pivot = v[low];  // Choisir le pivot (premier élément)
        int i = low, j = high;
        
        while (i < j) {
            while (v[i] <= pivot && i < high) i++;
            while (v[j] > pivot) j--;
            if (i < j) std::swap(v[i], v[j]);
        }
        std::swap(v[low], v[j]); // Placer le pivot à sa position finale

        quickSort(v, low, j - 1); // Tri de la partie gauche
        quickSort(v, j + 1, high); // Tri de la partie droite
    }
}

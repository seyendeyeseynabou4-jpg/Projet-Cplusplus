#include <vector>

void merge(std::vector<int>& v, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        merge(v, left, mid); // Tri de la moitié gauche
        merge(v, mid + 1, right); // Tri de la moitié droite
        
        // Fusionner les deux moitiés triées
        std::vector<int> temp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (v[i] <= v[j]) {
                temp.push_back(v[i++]);
            } else {
                temp.push_back(v[j++]);
            }
        }
        while (i <= mid) temp.push_back(v[i++]);
        while (j <= right) temp.push_back(v[j++]);

        for (int k = 0; k < temp.size(); k++) {
            v[left + k] = temp[k]; // Copier les éléments fusionnés dans le vecteur original
        }
    }
}

void mergeSort(std::vector<int>& v) {
    merge(v, 0, v.size() - 1);
}

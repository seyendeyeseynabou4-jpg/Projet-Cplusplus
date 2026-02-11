#include <iostream>
#include "trie.hpp"


void selection_sort(std::vector<int>& v) {
    size_t n = v.size();
    for (size_t i = 0; i < n; ++i) {
        // trouver l'indice du plus petit élément dans la partie non triée
        size_t min = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (v[j] < v[min])
                min = j;
        }
        // échanger l'élément courant avec le plus petit trouvé
        if (i != min)
            std::swap(v[i], v[min]);
    }
}

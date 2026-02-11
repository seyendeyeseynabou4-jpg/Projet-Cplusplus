#include <iostream> 
#include <vector>
#include "trie.hpp"


// Avec std::sort

void trie_sort(std::vector <int> &v){

    std::sort(v.begin(),v.end());
}

void trie_sort(std::vector<int>& v) {
    size_t n = v.size();
    for (size_t i = 0; i < n; ++i) {
        // trouver l'indice du plus petit élément dans la partie non triée
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (v[j] < v[min_idx])
                min_idx = j;
        }
        // échanger l'élément courant avec le plus petit trouvé
        if (i != min_idx)
            std::swap(v[i], v[min_idx]);
    }
}

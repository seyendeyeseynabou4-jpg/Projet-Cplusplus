#include <iostream>
#include <vector>
#include <chrono>
#include "trie.hpp"

// Fonction générale pour tester un tri
void benchmark(void (*tri_func)(std::vector<int>&), const std::string &nom, int n, int type) {
    // 1. Générer le tableau
    std::vector<int> tab = creattab(n, type);
    std::vector<int> v = tab; // copie pour le tri

    // 2. Mesurer le temps
    auto t_start = std::chrono::steady_clock::now();
    tri_func(v);
    auto t_end = std::chrono::steady_clock::now();

    size_t duration = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();

    // 3. Vérification automatique
    bool tri_correct = true;
    for (size_t i = 0; i + 1 < v.size(); i++) {
        if (v[i] > v[i + 1]) {
            tri_correct = false;
            break;
        }
    }

    // 4. Affichage
    std::cout << "Tri : " << nom << ", n = " << n << ", type = " << type
              << ", temps = " << duration << " µs";
    if (!tri_correct) std::cout << " -- ERREUR : tableau non trié !";
    std::cout << std::endl;
}



int main() {
    int tailles[] = {1000, 5000, 10000}; // tailles de tableau à tester
    int types[] = {1, 2, 3};             // type de tableau : aléatoire, moitié croissante, moitié décroissante

    for (int n : tailles) {
        for (int type : types) {
            benchmark(trie_sort, "trie_sort", n, type);
            benchmark(selection_sort, "selection_sort", n, type);
            benchmark(stableSort, "stableSort", n, type);
            benchmark(sort_insertion, "insertion_sort", n, type);
            benchmark(bubbleSort, "bubbleSort", n, type);
            benchmark(quicksort_det_rec, "quicksort_det", n, type);
            benchmark(quicksort_rand_rec, "quicksort_rnd", n, type);
        }
    }

    return 0;
}

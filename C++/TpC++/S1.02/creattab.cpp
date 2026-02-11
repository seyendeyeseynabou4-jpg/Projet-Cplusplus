#include <vector>
#include <cstdlib>
#include "trie.hpp"
std::vector<int> creattab(int n, int type) {
    std::vector<int> v(n);  // allocation directe (pas de push_back)

    // ===== TYPE 1 : valeurs aléatoires =====
    if (type == 1) {
        for (int i = 0; i < n; i++) {
            v[i] = rand() % (1024 * n);
        }
    }

    // ===== TYPE 2 : moitié croissante / moitié aléatoire =====
    else if (type == 2) {

        // Première moitié : valeurs croissantes
        for (int i = 0; i < n / 2; i++) {
            int r = rand() % 1024;
            v[i] = 1024 * i + r;
        }

        // Deuxième moitié : valeurs aléatoires
        for (int i = n / 2; i < n; i++) {
            v[i] = rand() % (1024 * n);
        }
    }

    // ===== TYPE 3 : moitié décroissante / moitié aléatoire =====
    else if (type == 3) {

        // Première moitié : valeurs décroissantes
        for (int i = 0; i < n / 2; i++) {
            int r = rand() % 1024;
            v[i] = 1024 * (n - i) + r;
        }

        // Deuxième moitié : valeurs aléatoires
        for (int i = n / 2; i < n; i++) {
            v[i] = rand() % (1024 * n);
        }
    }

    return v;
}

#include <vector>
#include "trie.hpp"

void sort_insertion (std::vector<int>& v) {
    size_t n = v.size();
    for (size_t i = 1; i < n; ++i) {
        int nbre = v[i];
        size_t j = i;
        while (j > 0 && v[j-1] > nbre) {
            v[j] = v[j-1];
            --j;
        }
        v[j] = nbre;
    }
}

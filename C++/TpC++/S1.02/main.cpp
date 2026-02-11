#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "trie.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <n> <type>" << std::endl;
        return 1;
    }
    
    int n = std::atoi(argv[1]);
    int type = std::atoi(argv[2]);
    
    srand(time(NULL));
    
    std::vector<int> v = creattab(n, type);
    
    auto t_start = std::chrono::steady_clock::now();
    tri_sort(v);  // Cette fonction sera définie par le wrapper
    auto t_end = std::chrono::steady_clock::now();
    
    size_t duration = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
    
    std::cout << n << " " << duration << std::endl;
    
    return 0;
}
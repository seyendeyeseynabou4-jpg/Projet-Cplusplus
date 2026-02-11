#include <iostream>
#include <vector>
#include "test.hpp"
#include <cstdlib>

int main(){
    //srand(time(0)); est une fonction qui initialise le generateur de nbres aleaoires rand()
    int n = 20;
    // int type ;
    
    std::vector <int> tab = creattab(n, 1); 
    std::cout << "Pour le type 1 : " << std::endl; 
    for(size_t i =0; i < tab.size(); i++){
        std::cout << tab[i] << std::endl;
    }
    tab = creattab(n, 2); 
    std::cout << "Pour le type 2: "  << std::endl;
    for(size_t i = 0 ; i < tab.size(); i++){
        std::cout << tab[i] << std::endl;
    }
    tab = creattab(n, 3);
    std::cout << "POur le type 3 " << std::endl;
    for(size_t i = 0; i < tab.size(); i++){
        std::cout << tab[i] << std::endl;
    }

    return 0;

}


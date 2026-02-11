#include <iostream> 
#include <vector>
#include "exo1.hpp"

std::vector <int> liste(std::vector <int> v){
    std::vector <int> tab;
    for(size_t i=0; i<v.size(); i++){
        tab= v[i];
    }
    return tab;
}

void afficher(const std::vector <int> &valeurs){
    for(int x: valeurs)
        std::cout << x << std::endl; 
}

std::vector <int> ordre_croissant( std::vector <int> &v){
    std::vector <int> tab=v ; 
    for(size_t i=0; i< tab.size(); i++){
         if(tab[i]>tab[i+1]){
            std::swap (tab[i], tab[i+1]);
         }
    }
    return tab;
}
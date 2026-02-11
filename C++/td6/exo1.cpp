#include <iostream>
#include <vector> 
#include <string> 
#include <algorithm>
#include "exo1.hpp" 

std::vector <int> liste(){
    std::string s ; 
    std::vector <int> v ; 
    std::cout <<"Donnez une liste d'entiers:" << std::endl;
    while(std::getline(std::cin, s) && !s.empty()){
        int n=std::stoi(s) ;
        v.push_back(n);
    }
    return v; 
}

void afficher(const std::vector <int> &v){
    for(int x: v) 
        std::cout << x << " " << std::endl;
    std::cout << std::endl;
}
void ordre_croissant(const std::vector <int> &v){
    std::vector <int> v2 =v; 
    std::sort(v2.begin(), v2.end()); 
    afficher(v2);
}
void delete_doublon(const std::vector <int> &tab){
    std::vector <int> v=tab;
    std::sort(v.begin(), v.end());
    int compteur = v[0] +1; 
    
    for(int x: v){
        if(compteur!=x)
        std::cout<< x << std::endl ; 
        compteur=x ;
    } 
}

int main(){
    std::vector <int> v=liste(); 
    afficher(v); 
    std::cout << "Liste apres trie: " << std::endl;
    ordre_croissant(v); 
    delete_doublon(v);
    std::cout << "Liste apres deuxieme trie";
    // afficher(v); 
    return 0; 
}
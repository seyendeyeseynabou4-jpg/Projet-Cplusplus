
#include <iostream>
#include <vector>
#include"color.hpp"
int main(){
    size_t nb;
    std::vector <RGB> couleur;
    do{
        std::cout <<"Entrer le nombre de couleurs à saisir> " ;
        std::cin>> nb;
        if(nb > 8){
            std::cout <<"Erreur : Vous ne pouvez pas saisir plus de 8 couleurs." <<std::endl;
            std::cout << "Entrer le nombre de couleurs à saisir> " ;
        } 
    }while(nb > 8);

    for(size_t i=0; i< nb ; i++){
        std::cout << "Saisissez la couleur "<< i+1 <<"(R, G, B):" << std::endl ; 
        couleur.push_back(demander_couleur_RGB());
    }
    std::cout << "============== Liste des couleurs ==========" <<std::endl; 

 for(size_t i = 0; i < couleur.size(); i++){
        std::cout << "RGB(" << couleur[i] << ")";
        if(i < couleur.size() - 1)
            std::cout << ';';
        std::cout << std::endl;
    }
    return 0;

    
}

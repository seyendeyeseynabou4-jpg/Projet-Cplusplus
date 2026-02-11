#include <iostream> 
#include "exo1.hpp"

unsigned char valeur_de_la_couleur(std::string msg){
    
    do{
        std::cout <<msg <<std::endl;
    }
}

int main(){

    size_t nb_color;
   do{
        std::cout << "Entrer le nombre de couleur à saisir> ";
        std::cin>> nb_color;
        if(nb_color >8){
            std::cout <<"Vous ne pouvez pas saisir plus 8 couleurs." <<std::endl ;
            std::cout <<"Entrer le nombre de couleurs à saisir> ";
        }
        
    
    } while(nb_color > 8);

}
#include <iostream>
#include "exo1.hpp"

void entrer_un_nombre(int &nombre)
{
    std::cout<< "Donnez un nombre:";
    std::cin>> nombre;
}


void entrer_un_intervalle(int &borne_inf , int &borne_sup)
{
    std::cout << "Donnez la borne inferieure de l'intervalle" << std::endl;
    std::cin >> borne_inf;
    
    std::cout << "Donnez la borne superieure de l'intervalle" << std::endl;
    std::cin >> borne_sup;
    
}

int main()
{
    int nombre , borne_sup , borne_inf ;
    entrer_un_nombre(nombre);
    entrer_un_intervalle(borne_inf , borne_sup);
    if(nombre >= borne_inf && nombre <= borne_sup)
        std::cout << "Ce nombre est compris dans l'intervalle" << std::endl;

         else 
         std::cout << "Ce nombre n'est pas dans l'intervalle" << std::endl;

    if(borne_inf > borne_sup)
            std::cout<< "L'intervalle que vous avez saisi est incorect car la borne inferieure est superieure a la borne superieure!! ";
   
 return 0 ;

}
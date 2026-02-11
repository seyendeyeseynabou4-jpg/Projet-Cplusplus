#include <iostream>

#include "exo1.hpp"


void borne_intervalle(int &borne_inf , int &borne_sup)
{
    std::cout << "Donnez la borne inferrieure de l'intervalle:";
    std::cin >> borne_inf;
    std::cout << "Donnez la borne superieure de l'intervalle:";
    std::cin >> borne_sup;
   
}

void verification_intervalle(int &nombre, int borne_inf , int borne_sup )
{
    std::cout << "Donnez un nombre:";
    std::cin >> nombre;

    if (nombre < borne_inf || nombre > borne_sup)
    {
        std::cout << "ce nombre n'est pas dans l'intervalle:";
    }
    else
        std::cout << "Le nombre est dans l'intervalle" << std::endl;
}

void echange(int &borne_inf , int &borne_sup)
{
    int temp;
    temp = borne_inf;
    borne_inf = borne_sup;
    borne_sup = temp;
}


int main()
{
    int nombre;
    int borne_inf , borne_sup;
    borne_intervalle(borne_inf , borne_sup);
    verification_intervalle(nombre,borne_inf , borne_sup);
    if(borne_inf > borne_sup)
        echange(borne_inf , borne_sup);
    return 0;
}
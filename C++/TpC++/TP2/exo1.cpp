#include <iostream>
#include "exo1.hpp"

void demande_nombre(int &nombre)
{
    std::cout << "donnez un nombre:";
    std::cin >> nombre;
}

int main()
{
    int nombre; 
    demande_nombre(nombre);
    if (nombre > 0)
        std::cout << "Ce nombre est positif" << std::endl;
    else 
        if(nombre < 0)
            std::cout << "Ce nombre est negatif"<< std::endl;
        else 
             std::cout << "Ce nombre est null"<< std::endl;
    return 0;
           

}



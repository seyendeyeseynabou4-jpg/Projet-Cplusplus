#include <iostream>
#include "exo1.hpp"

int sasir_nombre(int &nombre)
{
    std::cout << "Donnez un nombre:";
    std::cin >> nombre;
    return nombre;
}
int main()
{
    int nombre;
   sasir_nombre(nombre);
   if(nombre <0)
    std::cout << "Le nombre est negatif"<< std::endl;
    else 
     if(nombre > 0)
      std::cout << "Le nombre est positif" << std::endl;
     else 
        std::cout << "Le nombre est nul"<< std::endl;
    return 0;
}
 
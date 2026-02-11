#include <iostream>
#include <string>
#include "exo4.hpp"

void saisir_chaine_de_caractere( std::string &chaine )
{
    std::cout << "Donnez une chaine de caractere:";
    std::cin >> chaine;
}



void verification ( std::string chaine )
{
    int i = 0 ;
    for(char x:chaine)
    {
        if(x == 'o' || x== 'a' || x== 'e' || x== 'i' || x== 'u' || x== 'y')
        i += 1 ;
    }
    std::cout << "La chaine contient " << i << " voyelles" << std::endl;       
}


void verification_nombre (int &nombre)
{
    std::cout << "Donnez un nombre:";
    std::cin >> nombre;
    while ( nombre % 2 == 0 || nombre < 0)
    {
        std::cout << "Donnez un nombre impair et positif:";
        std::cin >> nombre;
    }
   
}
int main()
{
    int nombre;
    std::string chaine;
    saisir_chaine_de_caractere(chaine);
    verification (chaine);
    verification_nombre (nombre);
    return 0;
}
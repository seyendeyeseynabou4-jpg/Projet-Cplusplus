#include <iostream>
#include "TPExo1.hpp"

void heures( int &heure){
    std::cout << "Entrez le nombre d'heures : ";
    std::cin >> heure;
}
void minutes( int &minute){
    std::cout << "Entrez le nombre de minutes : ";
    std::cin >> minute;
}
void secondes( int &seconde){
    std::cout << "Entrez le nombre de secondes : ";
    std::cin >> seconde;
}

int main(){
    int heure , minute , seconde;
    heures (heure);
    minutes (minute);
    secondes (seconde);
    std::cout << "Il est " << heure << ":" << minute << ":" << seconde << ":" << std::endl;
    return 0;
}
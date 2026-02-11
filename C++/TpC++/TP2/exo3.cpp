#include <iostream>
#include "exo3.hpp"

void age_utilisateur(int &age)
{
    std::cout << "Donnez votre age:";
    std::cin>> age;
}

int main()
{
    int age ; 
    age_utilisateur(age);
    if (age >= 18)
        std::cout << "Vous etes majeur" << std::endl;
    else
        std::cout << "Vous etes mineur" << std::endl;
    return 0;

}
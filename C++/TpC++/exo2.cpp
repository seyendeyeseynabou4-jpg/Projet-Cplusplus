#include <iostream>
#include <string>

#include "exo2.hpp"

void nom_utilisateur(std:: string &nom){
    std:: cout << "Donnez votre nom :";
    std:: cin >> nom; 
}
void age_utilisateur (int &age){
    std:: cout << "Donnez votre age:";
    std:: cin >> age;
}

int main(){
    std::string nom;
    int age;
    nom_utilisateur(nom);
    age_utilisateur(age);
    std::cout << "bonjour" << " " << nom << ", vous avez" << " " <<age << " "<< "ans" << std::endl;
    return 0;
}

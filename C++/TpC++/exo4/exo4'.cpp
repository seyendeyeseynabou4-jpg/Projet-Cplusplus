#include <iostream>
#include "exo4.hpp"

void valeurs( char &a, char &b){
    std:: cout << "Donnez la valeur de a :";
    std:: cin >> a;
    std:: cout << "Donnez la valeur de b :";
    std:: cin >> b;
}

void permutation(char &a, char &b){
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    char n1 , n2 ;
    valeurs (n1,n2);
    permutation (n1,n2);
    std::cout << "la nouvelle valeur de a apres permutation est:" << n1 << std::endl << "la nouvelle valeur de b apres permutation est:"<< n2 << std::endl;
    return 0;
    }
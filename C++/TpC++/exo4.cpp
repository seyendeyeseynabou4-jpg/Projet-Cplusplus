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

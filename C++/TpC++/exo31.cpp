#include<iostream>

#include "exo31.hpp"

void valeurs (int &a , int &b ){
    std::cout << "donnez une valeur pour a:";
    std::cin >> a ;

    std::cout << "donnez une autre valeur pour b: ";
    std::cin >> b ;
    }

void permutation (int &a, int&b){
    a = a + b;
    b = a -b ;
    a = a - b ;
}

int main() {
    int n1 , n2 ;
    valeurs (n1,n2);
    permutation (n1,n2);
    std::cout << "la nouvelle valeur de a apres permutation est:" << n1 << std::endl << "la nouvelle valeur de b apres permutation est:"<< n2 << std::endl;
    return 0;
    }

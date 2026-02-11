#include <iostream>
#include "exo3.hpp"

void valeurs( int &a, int &b){
    std:: cout << "Donnez la valeur de a :";
    std:: cin >> a;
    std:: cout << "Donnez la valeur de b :";
    std:: cin >> b;
}

void permutation(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int n1 , n2 ;
    valeurs(n1,n2);
    permutation(n1,n2);

    std::cout << "la nouvelle valeur de a apres permutation est:" << n1 << std::endl << "la nouvelle valeur de b apres permutation est:"<< n2 << std::endl;
    return 0;

}
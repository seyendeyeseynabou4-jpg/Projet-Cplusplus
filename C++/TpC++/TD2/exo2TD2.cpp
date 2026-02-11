#include <iostream>
int main() {
    int nombre;
    int a , b;
    std::cout << "Donnez un nombre:" ;
    std::cin >> nombre;
    std::cout << "Donnez le premier borne de l'intervalle:" ;
    std::cin >> a;
    std::cout << "Donnez le deuxieme borne de l'intervalle:" ;
    std::cin >> b;
    if (a > b) {
        std::cout << "L'intervalle est invalide car la premiere borne est superieure a la deuxieme borne." << std::endl;
    }   
    else if (nombre >= a && nombre <= b) {
            std::cout << "le nombre est dans l'intervalle" << std::endl;
        } else {
            std::cout << "le nombre n'est pas dans l'intervalle" << std::endl;
    } 

    return 0;
}
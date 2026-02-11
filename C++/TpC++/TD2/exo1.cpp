#include <iostream>
int main() {
    int nombre;
    std::cout << "donnez un nombre:" ;
    std::cin >> nombre;
    if (nombre >0) {
        std::cout << "le nombre est positif" << std::endl;
    } else if (nombre <0) {
        std::cout << "le nombre est negatif" << std::endl;
    } else {
        std::cout << "le nombre est nul" << std::endl;
    }
    return 0;
}

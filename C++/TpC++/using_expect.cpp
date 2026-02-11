#include <iostream> 
int main(){
    std::cout <<"Combien de valeurs ?>";
    size_t combien=0;
    std::cin >> combien;
    double somme = 0, valeur ;
    for(size_t i=0; i<combien; i++){
        std::cout << "Valeurs ?>";
        std::cin >> valeur;
        somme+= valeur;
    }
    std::cout << "La moyenne est " << somme/combien <<"." << std::endl;
    return 0;
}
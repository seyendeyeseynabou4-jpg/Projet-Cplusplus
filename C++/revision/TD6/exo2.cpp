#include <iostream>
#include <string>
#include <algorithm>
#include <map>



// // .count() est une méthode de std::map
// // Elle vérifie si une clé existe dans la map et retourne :

// // 1 si la clé existe
// // 0 si la clé n'existe pas
// if(voyelle.count(i) > 0)  // ✅ Vérifie si i est une voyelle dans la map

void voyelle_a_num(std::string &s ){
    std::map <char , int> voyelle;
    voyelle['a'] =  1;
    voyelle['e'] =  2; 
    voyelle['i'] =  3;
    voyelle['o'] =  4;
    voyelle['u'] =  5;  
    for(char &i:s){
        if(voyelle.count(i) > 0)
            i = '0' + voyelle[i];
    }
}

int main(){
    std::string chaine ;
    std::cout << "Donnez une chaine de caractere:" ;
    std::cin >> chaine ;
    voyelle_a_num(chaine);
    std::cout << "La nouvelle chaine: " << chaine <<std::endl;
    return 0;

}
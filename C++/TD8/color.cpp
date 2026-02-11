#include <iostream> 
#include <vector>
#include "color.hpp"

unsigned char demander_composante(std::string msg){
    size_t comp;
    do{
        std::cout << msg ;
        std::cin >> comp;
        if(comp > 255){
            std::cout <<"Erreur: cette valeur n'est pas permise." <<std::endl;
            std::cout << "Vous devez saisir un nombre sur l'intervalle [0,255]."<<std::endl;
            std::cin >> comp;
        }
    } while(comp > 255);
    return (unsigned char)(comp);
}

RGB demander_couleur_RGB(){
    RGB c ;
    c.r=demander_composante("R> ");
    c.g=demander_composante("G> ");
    c.b=demander_composante("B> ");
    return c ;
}

// void affichage()


// Cette fonction permet de convertir les nombres en caracteres
// Unsigned char et char stockent des nombres entre 0 et 255 donc on a pas besoin de faire la convertion avant de retourner v le compilateur le fera directement 
// char valeur_vers_hex(unsigned char v){
//     if(v < 10)
//         return '0' +v  //POUR FAIRE LA CONVERSION D'UN NOMBRE VERS UN CARACTERE
//     else
//         return 'A' + ( v- 10);
    
// }

// // Cette fonction permet de convertir de RGB vers HEX 

// std::string RGD_vers_HEX(unsigned char rgb){
//     std::string hex="";
//    unsigned char v0 = rgb % 16;
//    unsigned char v1 = (rgb - v0) / 16;
//    hex+=valeur_vers_hex(v1);
//    hex+=valeur_vers_hex(v0);
//    return hex ;
// }



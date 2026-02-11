#ifndef EXO1_HPP
#define EXO1_HPP

    struct RGB{
       unsigned char r , g , b ;
    };
unsigned char demander_composante(std::string msg);

RGB demander_couleur_RGB();

void afficher();


// Cette fonction permet de convertir les nombres en caracteres
char valeur_vers_hex(unsigned char v);

std::string RGD_vers_HEX(unsigned char rgb);
std::string RGD_vers_HEX(unsigned char rgb);

#endif
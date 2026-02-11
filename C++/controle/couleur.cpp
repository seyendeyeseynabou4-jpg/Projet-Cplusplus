#include "couleur.hpp"

// fonction qui demande et controle le nombre de couleurs à entrer
void control_saisie_nb_couleur(size_t& nb){
    do
    {
        std::cout << "Entrer le nombre de couleur à saisir > ";
        std::cin >> nb;
        if (nb > 8)
            std::cout << "Vous avez entré " << nb << "> 8; vous ne povez pas entrer plus de 8 couleurs" << std::endl;
    } while (nb > 8);
}

// Fonction qui controle la saisie des composantes rouge, verte, bleue
unsigned char demander_composante(std::string msg)
{
    size_t comp;
    do
    {
        std::cout << msg ;
        std::cin >> comp;
        if (comp > 255){
            std::cout << "Erreur : cette valeur n'est pas permise." << std::endl;
            std::cout << "Vous devez saissir un nombre sur l'intervale [0, 255]." << std::endl;
        }
    } while (comp > 255);
    unsigned char comp2 = (unsigned char)comp;
    return comp2;
}

// Fonction pour la saisie des couleurs (R, G, B)
RGB demander_couleur_RGB()
{
    RGB c;
    c.r = demander_composante("R> ");
    c.g = demander_composante("G> ");
    c.b = demander_composante("B> ");
    return c;
}


//HEXADECIMAL

std::string composante_hex(unsigned char couleur){
    std::string str;
    std::string hex = "0123456789ABCDEF";
    int valeur_A = couleur % 16;
    int valeur_B = (couleur - valeur_A)  / 16;
    str = hex[valeur_B];
    str += hex[valeur_A];

    return str;
}

std::string convert_rgb_to_hex(RGB couleurs){
    std::string r_hex = composante_hex(couleurs.r);
    std::string g_hex = composante_hex(couleurs.g);
    std::string b_hex = composante_hex(couleurs.b);

    return ("#" + r_hex + g_hex + b_hex); 
}

//vers HSL

//Fonction qui renvoie le max
double max(const double& a, const double& b, const double& c){
    if (a >= b && a >= c)
        return  a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

double min(const double& a, const double& b, const double& c){
    if (a <= b && a <= c)
        return  a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

HSL rgb_to_hsl(RGB c){
    double denominateur = 255.0;
    double r_prime = static_cat<double> (couleurs.r) / denominateur;
    double g_prime = static_cat<double> (couleurs.g) / denominateur;
    double b_prime = static_cat<double> (couleurs.b) / denominateur;
    double minimum = min()
    


}

// //LISTER COULEURS
// void lister_couleurs(std::vector<RGB> couleurs){
//     for(size_t i = 0; i < nb; i++)[
//         std::cout<< "Couleur "<< i+1 <<":"<<std::endl;
//         cout<<"RGB("<<couleur.r<< ", "<<
//     ]
// }


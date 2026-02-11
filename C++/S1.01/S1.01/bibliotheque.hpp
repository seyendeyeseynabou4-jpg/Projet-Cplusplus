#ifndef BIBLIOTHEQUE_HPP
#define BIBLIOTHEQUE_HPP

#include <string>
#include <vector>




struct Date {
    int jour;
    int mois;
    int annee;
};

struct Livre {
    std::string titre;
    std::vector<std::string> auteurs;
    std::string ISBN;
    std::string description;
    std::string langue;
    std::string genre;
    Date dateparution;
    std::string logo;
};


struct Bibliotheque {
    std::string titre;
    std::string description;
    std::vector<Livre> livres;

};

// Fonctions utilitaires
std::vector<std::string> split(const std::string& str, char delim);
bool estNumerique(const std::string& str);
bool estIsbnValide(const std::string& isbn);
bool isbnExisteDeja(const Bibliotheque &bibliotheque, const std::string& isbn) ;
bool Datevalide(const Date &d) ;
Date lireDate();
#endif

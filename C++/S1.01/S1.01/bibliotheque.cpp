#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>


#include "bibliotheque.hpp"

using namespace std; 



vector<string> split(const string& str, char delim) {
    vector<string> parties;
    stringstream ss(str);
    string partie;

    while (getline(ss, partie, delim)) {
        parties.push_back(partie);
    }

    return parties;
}


// Vérifie si une chaîne ne contient que des chiffres
bool estNumerique(const string& str) {
    if (str.empty())
        return false;

    for (char c : str) {
        if (!isdigit(static_cast<unsigned char>(c)))
            return false;
    }
    return true;
}


// Vérifie si un ISBN est valide (ISBN-13 avec tirets)

bool estIsbnValide(const string& isbn) {
    // Vérification du format ISBN : doit être de type ISBN-13
    vector<string> parties = split(isbn, '-');
    
    // Vérification du format : 5 parties séparées par des tirets
    if (parties.size() != 5) {
        return false;
    }

    string prefixeEan = parties[0];
    string groupeLinguistique = parties[1];
    string codeEditeur = parties[2];
    string numeroPublication = parties[3];
    string chiffreControle = parties[4]; 

    // Vérifier si chaque partie est numérique
    if (!estNumerique(prefixeEan) || 
        !estNumerique(groupeLinguistique) || 
        !estNumerique(codeEditeur) || 
        !estNumerique(numeroPublication) || 
        !estNumerique(chiffreControle)) {
        return false;
    }

    // Vérification du format de l'ISBN (978 ou 979)
    if (prefixeEan != "978" && prefixeEan != "979") {
        return false;
    }

    // Calcul du chiffre de contrôle selon la formule ISBN-13
    string tousLesChiffres = prefixeEan + groupeLinguistique + 
                             codeEditeur + numeroPublication + 
                             chiffreControle;

    int somme = 0;
    for (size_t i = 0; i < 12; ++i) {
        int chiffre = tousLesChiffres[i] - '0';
        somme += (i % 2 == 0) ? chiffre : chiffre * 3;
    }
            
    int controleCalcule = (10 - (somme % 10)) % 10;
    int controleSaisi = tousLesChiffres[12] - '0';
    
    return controleCalcule == controleSaisi;
}
bool Datevalide(const Date &d) {
    if (d.annee < 0) return false;
    if (d.mois < 1 || d.mois > 12) return false;
    if (d.jour < 1) return false;

    int joursParMois[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (d.mois == 2) {
        bool bissextile =
            (d.annee % 4 == 0 && d.annee % 100 != 0) ||
            (d.annee % 400 == 0);
        return d.jour <= (bissextile ? 29 : 28);
    }

    return d.jour <= joursParMois[d.mois - 1];
}

Date lireDate() {
    Date d;
    while (true) {
        std::string ligne;
        std::cout << "Date de parution (jj mm aaaa) : ";
        std::getline(std::cin, ligne);

        std::istringstream iss(ligne);
        if (iss >> d.jour >> d.mois >> d.annee) {
            // Appeler la fonction Datevalide pour vérifier si c'est une vraie date
            if (Datevalide(d)) {
                return d;  // date correcte
            } else {
                std::cout << "Date invalide. Veuillez réessayer.\n";
            }
        } else {
            std::cout << "Format invalide. Veuillez entrer trois nombres.\n";
        }
    }
}


bool isbnExisteDeja(const Bibliotheque &bibliotheque, const string& isbn) {
    for (const Livre& livre : bibliotheque.livres) {
        if (livre.ISBN == isbn) {
            return true;
        }
    }
    return false;
}

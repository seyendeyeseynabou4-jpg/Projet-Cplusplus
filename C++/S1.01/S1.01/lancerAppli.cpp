#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

#include "lancerAppli.hpp"


void intitule_bibliotheque(std::string &titre, std::string &description) {

    std::cout << "Entrez le titre de la bibliotheque : ";
    std::getline(std::cin, titre);

    std::cout << "Entrez la description de la bibliotheque\n";
    std::cout << "(terminez par une ligne contenant un seul point)\n";

    description.clear();
    std::string ligne;

    while (true) {
        std::getline(std::cin, ligne);
        if (ligne == ".") {
            break;
        }
        description += ligne + "\n";
    }
}


void initialiser_projet(const std::string &filename, Bibliotheque &bibliotheque) {

    // Nettoyage de la bibliotheque avant chargement
    bibliotheque.titre.clear();
    bibliotheque.description.clear();
    bibliotheque.livres.clear();

    std::ifstream fichier(filename);

    if (!fichier.is_open()) {
        std::cout << "Le fichier n'existe pas. Creation d'une nouvelle bibliotheque.\n";

        // Nettoyer le buffer avant getline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        intitule_bibliotheque(bibliotheque.titre, bibliotheque.description);
        return;
    }

    std::cout << "***** Chargement de la bibliotheque existante *****\n";

    std::string ligne;
    std::string section;

    while (std::getline(fichier, ligne)) {

        if (ligne == "[TITRE]" || ligne == "[DESCRIPTION]" || ligne == "[LIVRES]") {
            section = ligne;
            continue;
        }

        if (section == "[TITRE]") {
            bibliotheque.titre = ligne;
        }
        else if (section == "[DESCRIPTION]") {
            if (!bibliotheque.description.empty()) {
                bibliotheque.description += "\n";
            }
            bibliotheque.description += ligne;
        }
        else if (section == "[LIVRES]") {

            if (ligne == "Livre") {
                Livre livre;

                while (std::getline(fichier, ligne) )/*&& ligne != "------------------")*/ {

                    if (ligne.find("Titre : ") == 0) {
                        livre.titre = ligne.substr(8);
                    }
                    else if (ligne.find("ISBN : ") == 0) {
                        livre.ISBN = ligne.substr(7);
                    }
                    else if (ligne.find("Langue : ") == 0) {
                        livre.langue = ligne.substr(9);
                    }
                    else if (ligne.find("Genre : ") == 0) {
                        livre.genre = ligne.substr(8);
                    }
                    else if (ligne.find("Date : ") == 0) {
                        std::istringstream iss(ligne.substr(7));
                        char delim;
                        iss >> livre.dateparution.jour
                            >> delim
                            >> livre.dateparution.mois
                            >> delim
                            >> livre.dateparution.annee;
                    }
                    else if (ligne.find("Auteur : ") == 0) {
                        livre.auteurs.push_back(ligne.substr(9));
                    }
                    else if (ligne.find("Description : ") == 0) {
                        livre.description = ligne.substr(14);
                        while (std::getline(fichier, ligne) && ligne != "FinDescription") {
                            livre.description += "\n" + ligne;
                        }
                    }
                }

                bibliotheque.livres.push_back(livre);
            }
        }
    }

    fichier.close();
}

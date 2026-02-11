#include <iostream>
#include <fstream>
#include <limits>
#include <cctype>
#include <sstream> 
#include <string>


#include "gererbibliotheque.hpp"
#include "menu.hpp"

using namespace std;


string titreSansArticle(const string &titre) {
    string t = titre;

    // Supprimer les espaces au début
    while (!t.empty() && t[0] == ' ')
        t.erase(0, 1);

    // Version minuscule pour comparaison
    string tMin = t;
    for (char &c : tMin) c = tolower(c);

    // Liste des articles
    const string articles[] = {
        "le ", "la ", "les ", "l'", "un ", "une ", "des "
    };

    for (const string &a : articles) {
        if (tMin.rfind(a, 0) == 0) { // commence par l’article
            t.erase(0, a.length());
            break;
        }
    }

    return t;
}


void importerDepuisCSV(Bibliotheque &bibliotheque) {
    string chemin;
    std::cout << "Chemin du fichier CSV : ";
    getline(std::cin, chemin);

    std::ifstream fichier(chemin);
    if (!fichier) {
        std::cout << "Erreur : impossible d'ouvrir le fichier.\n";
        return;
    }

    std::string ligne;
    getline(fichier, ligne); // ignorer l'en-tête

    while (getline(fichier, ligne)) {
        std::stringstream ss(ligne);
        std::string champ;

        Livre livre;

        // ISBN
        getline(ss, livre.ISBN, ';');

        // Vérifier ISBN
        if (!estIsbnValide(livre.ISBN)) {
            std::cout << "ISBN invalide ignore : " << livre.ISBN << std::endl;
            continue;
        }

        // Vérifier unicité
        bool existe = false;
        for (const auto &l : bibliotheque.livres) {
            if (l.ISBN == livre.ISBN) {
                existe = true;
                break;
            }
        }
        if (existe) {
            std::cout << "ISBN deja existant : " << livre.ISBN << std::endl;
            continue;
        }

        // Titre
        getline(ss, livre.titre, ';');

        // Langue
        getline(ss, livre.langue, ';');

        // Auteurs 
        std::string auteursStr;
        getline(ss, auteursStr, ';');
        std::stringstream sa(auteursStr);
        std::string auteur;
        while (getline(sa, auteur, ',')) {
            livre.auteurs.push_back(auteur);
        }

        // Date
        std::string dateStr;
        getline(ss, dateStr, ';');
        std::stringstream sd(dateStr);
        char sep;
        sd >> livre.dateparution.jour >> sep
           >> livre.dateparution.mois >> sep
           >> livre.dateparution.annee;

        if (!Datevalide(livre.dateparution)) {
            std::cout << "Date invalide pour ISBN : " << livre.ISBN << std::endl;
            continue;
        }

        // Description 
        getline(ss, livre.description, ';');

        // Genre
        getline(ss, livre.genre);

        bibliotheque.livres.push_back(livre);
    }

    std::cout << "Import CSV termine.\n";
}


void gerer_les_references(Bibliotheque &bibliotheque) {
    int choix = -1;

    while (choix != 0) {

    

        cout << "\n===== GERER LES REFERENCES =====" << endl;
        cout << "1 - Ajouter un livre" << endl;
        cout << "2 - Supprimer tous les livres" << endl;
        cout << "3 - Importer des livres depuis un fichier CSV" << endl;
        cout << "0 - Retour" << endl;
        cout << "> ";

        cin >> choix;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choix == 1) {
            ajouterLivre(bibliotheque);
        }
        else if (choix == 2) {
            char confirmation;
            cout << "  Êtes-vous sûr de vouloir supprimer toutes les références ? (o/n) : ";
            cin >> confirmation;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (confirmation == 'o' || confirmation == 'O') {
                bibliotheque.livres.clear();
                cout << "  Toutes les références ont été supprimées." << endl;
            } else {
                cout << "   Suppression annulée." << endl;
            }
        }
        else if (choix == 3) {
            importerDepuisCSV(bibliotheque);
        }


    }
}



void consulter_les_references(const Bibliotheque & bibliotheque) {
    if (bibliotheque.livres.empty()) {
        std::cout << "  Aucun livre dans la bibliotheque." << std::endl;
        return;
    }

    std::cout << "===== LISTE DES LIVRES =====" << std::endl;
    for (size_t i = 0; i < bibliotheque.livres.size(); i++) {
        std::cout << i + 1 << " - " << bibliotheque.livres[i].titre
                  << " | ISBN : " << bibliotheque.livres[i].ISBN << std::endl;
    }

    std::cout << "  Choisissez un livre (0 pour retour) : ";
    std::string saisie;
    std::getline(std::cin, saisie);

    // Vérification que la saisie est un entier
    int choix;
    try {
        choix = std::stoi(saisie);
    } catch (...) {
        std::cout << " Entrée invalide. Retour au menu.\n";
        return;
    }

    if (choix <= 0 || choix > (int)bibliotheque.livres.size()) {
        return;
    }

    const Livre & l = bibliotheque.livres[choix - 1];

    std::cout << "\n===== DETAILS DU LIVRE =====" << std::endl;
    std::cout << "Titre : " << l.titre << std::endl;
    std::cout << "ISBN : " << l.ISBN << std::endl;
    std::cout << "Langue : " << l.langue << std::endl;
    std::cout << "Genre : " << l.genre << std::endl;
    std::cout << "Date de parution : " << l.dateparution.jour << "/"
              << l.dateparution.mois << "/" << l.dateparution.annee << std::endl;

    std::cout << "Auteurs :" << std::endl;
    for (const std::string & a : l.auteurs) {
        std::cout << "- " << a << std::endl;
    }

    std::cout << "Description :" << std::endl;
    std::cout << l.description << std::endl;
}


void ajouterLivre(Bibliotheque &bibliotheque) {

    Livre livre;

    cout << "Titre : ";
    getline(cin, livre.titre);

    /* ---------- ISBN ---------- */
    while (true) {
        cout << "ISBN : ";
        getline(cin, livre.ISBN);

        if (!estIsbnValide(livre.ISBN)) {
            cout << "ISBN invalide.\n";
            continue;
        }

        if (isbnExisteDeja(bibliotheque, livre.ISBN)) {
            cout << " Cet ISBN existe déjà.\n";
            continue;
        }

        break;
    }

    cout << "Langue : ";
    getline(cin, livre.langue);

    cout << "Genre : ";
    getline(cin, livre.genre);

    /* ---------- DATE ---------- */
bool dateOK = false;
while (!dateOK) {

    cout << "Date de parution (jj mm aaaa) : ";

    if (!(cin >> livre.dateparution.jour
              >> livre.dateparution.mois
              >> livre.dateparution.annee)) {

        cout << "Format invalide.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }

    if (!Datevalide(livre.dateparution)) {
        cout << " Date invalide.\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }

    dateOK = true;
}

cin.ignore(numeric_limits<streamsize>::max(), '\n');

    /* ---------- AUTEURS ---------- */
    cout << "Entrez les auteurs (ligne vide pour terminer) :" << endl;
    while (true) {
        string auteur;
        getline(cin, auteur);
        if (auteur.empty()) break;
        livre.auteurs.push_back(auteur);
    }

    // ---------- DESCRIPTION ---------- 
    cout << "Entrez la description (ligne vide pour terminer) :" << endl;
    string ligne;
    while (true) {
        getline(cin, ligne);
        if (ligne.empty()) break;
        livre.description += ligne + "\n";
    }

    bibliotheque.livres.push_back(livre);
    cout << "Livre ajouté avec succès.\n";
}

void afficherLivresAvecPagination(const vector<Livre> &livres) {
    const int pageSize = 5;  // Nombre de livres par page
    int total = livres.size();
    int pages = (total + pageSize - 1) / pageSize; // nombre total de pages
    int page = 0;

    while (true) {
        cout << "\n--- Page " << (page + 1) << " / " << pages << " ---\n";

        int start = page * pageSize;
        int end = min(start + pageSize, total);

        for (int i = start; i < end; ++i) {
            cout << i + 1 << " - " << livres[i].titre
                 << " | ISBN : " << livres[i].ISBN
                 << " | Code éditeur : " << livres[i].ISBN.substr(6, 3)  // Exemple pour extraire code éditeur
                 << endl;
        }

        cout << "\nOptions : [n] page suivante | [p] page précédente | [q] quitter affichage : ";
        char choix;
        cin >> choix;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choix == 'n' || choix == 'N') {
            if (page + 1 < pages) page++;
            else cout << "Vous êtes à la dernière page.\n";
        } else if (choix == 'p' || choix == 'P') {
            if (page > 0) page--;
            else cout << "Vous êtes à la première page.\n";
        } else if (choix == 'q' || choix == 'Q') {
            break;
        } else {
            cout << "Choix invalide.\n";
        }
    }
}

// Fonction principale de recherche
void chercher_une_reference(Bibliotheque &bibliotheque) {
    cout << "Rechercher par :\n";
    cout << "1 - ISBN\n2 - Titre\n3 - Code éditeur\nVotre choix : ";
    int critere;
    cin >> critere;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string motCle;
    vector<Livre> resultats;

    switch (critere) {
        case 1: // ISBN
            cout << "Entrez l'ISBN : ";
            getline(cin, motCle);
            for (const Livre &l : bibliotheque.livres) {
                if (l.ISBN == motCle) {
                    resultats.push_back(l);
                }
            }
            break;

        case 2: // Titre
            cout << "Entrez un mot du titre : ";
            getline(cin, motCle);
            for (const Livre &l : bibliotheque.livres) {
                string titreMin = l.titre;
                string motMin = motCle;
                // Mettre tout en minuscules pour la recherche insensible à la casse
                for (char &c : titreMin) c = tolower(c);
                for (char &c : motMin) c = tolower(c);

                if (titreMin.find(motMin) != string::npos) {
                    resultats.push_back(l);
                }
            }
            break;

        case 3: // Code éditeur
            cout << "Entrez le code éditeur : ";
            getline(cin, motCle);
            for (const Livre &l : bibliotheque.livres) {
                string codeEditeur = l.ISBN.substr(6, 3);
                if (codeEditeur == motCle) {
                    resultats.push_back(l);
                }
            }
            break;

        default:
            cout << "Critère invalide.\n";
            return;
    }

    if (resultats.empty()) {
        cout << "Aucun résultat trouvé.\n";
    } else {
        afficherLivresAvecPagination(resultats);
    }
}


    
void exporter_en_html(const Bibliotheque & bibliotheque) {

    string nomfichier = bibliotheque.titre  + ".html";
    ofstream fichier(nomfichier);

    if (!fichier) {
        cout << "Erreur lors de la creation du fichier HTML." << endl;
        return;
    }

    fichier << "<!DOCTYPE html>\n";
    fichier << "<html lang=\"fr\">\n";
    fichier << "<head>\n";
    fichier << "<meta charset=\"UTF-8\">\n";
    fichier << "<title>" << bibliotheque.titre << "</title>\n";
    fichier << "</head>\n";
    fichier << "<body>\n";

    // Titre en gras
    fichier << "<h1><strong>" << bibliotheque.titre << "</strong></h1>\n";
    fichier << "<p>" << bibliotheque.description << "</p>\n";

    fichier << "<hr>\n";
    fichier << "<p>\n";

    // Liens de navigation
    for (char c = '#'; c <= 'Z'; c++) {
        bool existe = false;

        for (const Livre & l : bibliotheque.livres) {
            string titreClassement = titreSansArticle(l.titre);
            char premiere = '#';
            if (!titreClassement.empty()) {
                premiere = toupper(titreClassement[0]);
                if (!isalpha(premiere)) premiere = '#';
            }

            if (premiere == c) {
                existe = true;
                break;
            }
        }

        if (existe) {
            fichier << "<a href=\"#" << c << "\">" << c << "</a> ";
        } else {
            fichier << c << " ";
        }

        if (c == '#') c = 'A' - 1;
    }

    fichier << "</p>\n";
    fichier << "<hr>\n";

    // Sections par lettre
    for (char c = '#'; c <= 'Z'; c++) {
        bool sectionVide = true;

        for (const Livre & l : bibliotheque.livres) {
            string titreClassement = titreSansArticle(l.titre);
            char premiere = '#';
            if (!titreClassement.empty()) {
                premiere = toupper(titreClassement[0]);
                if (!isalpha(premiere)) premiere = '#';
            }

            if (premiere == c) {
                sectionVide = false;
                break;
            }
        }

        if (!sectionVide) {
            fichier << "<h2 id=\"" << c << "\">" << c << "</h2>\n";

            for (const Livre & l : bibliotheque.livres) {
                string titreClassement = titreSansArticle(l.titre);
                char premiere = '#';
                if (!titreClassement.empty()) {
                    premiere = toupper(titreClassement[0]);
                    if (!isalpha(premiere)) premiere = '#';
                }

                if (premiere == c) {
                    fichier << "<h3>" << l.titre << "</h3>\n";
                    fichier << "<p><strong>ISBN :</strong> " << l.ISBN << "<br>\n";
                    fichier << "<strong>Langue :</strong> " << l.langue << "<br>\n";
                    fichier << "<strong>Genre :</strong> " << l.genre << "<br>\n";
                    fichier << "<strong>Date :</strong> "
                            << l.dateparution.jour << "/"
                            << l.dateparution.mois << "/"
                            << l.dateparution.annee << "<br>\n";

                    fichier << "<strong>Auteurs :</strong> ";
                    for (size_t i = 0; i < l.auteurs.size(); i++) {
                        fichier << l.auteurs[i];
                        if (i + 1 < l.auteurs.size()) fichier << ", ";
                    }
                    fichier << "</p>\n";

                    fichier << "<p>" << l.description << "</p>\n";
                }
            }
        }

        if (c == '#') c = 'A' - 1;
    }

    fichier << "</body>\n";
    fichier << "</html>\n";

    fichier.close();

    cout << "Export HTML termine : fichier cree!!" << endl;
}


void parametres(Bibliotheque & bibliotheque) {

    // Modifier le titre
    cout << "Titre actuel : " << bibliotheque.titre << endl;
    cout << "Nouveau titre (laisser vide pour conserver) : ";
    string nouveauTitre;
    getline(cin, nouveauTitre);
    if (!nouveauTitre.empty()) {
        bibliotheque.titre = nouveauTitre;
    }

    // Modifier la description
    cout << "Modifier la description ? (o/n) : ";
    char choix;
    cin >> choix;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (choix == 'o' || choix == 'O') {
        cout << "Nouvelle description (ligne vide pour terminer) :" << endl;
        bibliotheque.description.clear();
        string ligne;
        while (true) {
            getline(cin, ligne);
            if (ligne.empty()) break;
            bibliotheque.description += ligne + "\n";
        }
    }


}


bool quitterApplication(Bibliotheque &bibliotheque) {
    // Vérifier si la bibliothèque a été modifiée
    bool modifie = !bibliotheque.livres.empty(); // par exemple, tu peux ajuster selon ton indicateur réel

    if (!modifie) {
        cout << "Aucune modification en cours. Fermeture de l'application.\n";
        return true;
    }

    // Menu pour gérer les modifications
    while (true) {
        cout << "\nModifications en attente détectées.\n";
        cout << "1 - Sauvegarder et quitter\n";
        cout << "2 - Quitter sans sauvegarder\n";
        cout << "0 - Annuler et retourner au menu\n";
        cout << "Votre choix : ";

        int choix;
        if (!(cin >> choix)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrée invalide. Veuillez entrer un nombre.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choix == 1) {
            string fichier;
            cout << "Entrez le nom du fichier pour sauvegarder la bibliotheque : ";
            getline(cin, fichier);

            ofstream out(fichier);
            if (!out) {
                cout << "Erreur : impossible de creer le fichier !" << endl;
                return false; // ne pas quitter si échec
            }

            // Sauvegarde du titre et description
            out << "[TITRE]\n" << bibliotheque.titre << "\n";
            out << "[DESCRIPTION]\n" << bibliotheque.description << "\n";
            out << "[LIVRES]\n";

            // Sauvegarde de tous les livres
            for (const Livre &l : bibliotheque.livres) {
                out << "Livre\n";
                out << "Titre : " << l.titre << "\n";
                out << "ISBN : " << l.ISBN << "\n";
                out << "Langue : " << l.langue << "\n";
                out << "Genre : " << l.genre << "\n";
                out << "Date : " << l.dateparution.jour << "/" 
                    << l.dateparution.mois << "/" 
                    << l.dateparution.annee << "\n";

                for (const string &auteur : l.auteurs) {
                    out << "Auteur : " << auteur << "\n";
                }

                out << "Description : " << l.description << "\n";
                out << "FinDescription\n";
                out << "------------------\n";
            }

            out.close();
            cout << "Bibliothèque sauvegardée avec succès !\n";
            return true;
        }
        else if (choix == 2) {
            cout << "Quitter sans sauvegarder.\n";
            return true;
        }
        else if (choix == 0) {
            cout << "Annulation. Retour au menu principal.\n";
            return false;
        }
        else {
            cout << "Choix invalide. Veuillez entrer 0, 1 ou 2.\n";
        }
    }
}






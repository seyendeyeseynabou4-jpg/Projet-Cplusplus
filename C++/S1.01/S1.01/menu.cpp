#include <iostream>
#include <string>
#include <limits>

#include "menu.hpp"
#include "bibliotheque.hpp"
#include "lancerAppli.hpp"

using namespace std;

void logo(){
    cout << R"(
          .--.           .---.        .-.
         .---|--|   .-.     | B |  .---. |~|    .--.
      .--|===|Ch|---|_|--.__| O |--|:::| |~|-==-|==|---.
      |%%|NT2|oc|===| |~~|%%| O |--|   |_|~|CATS|  |___|-.
      |  |   |ah|===| |==|  | K |  |:::|=| |    |GB|---|=|
      |  |   |ol|   |_|__|  | S |__|   | | |    |  |___| |
      |~~|===|--|===|~|~~|%%|~~~|--|:::|=|~|----|==|---|=|
      ^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-'
)"  << endl; 

}
void afficherMenu() {
    cout << "\n=================================================\n";
    cout << "        GESTION DE BIBLIOTHEQUE       \n";
    cout << "=====================================================\n";
    cout << " 1 - Consulter les references\n";
    cout << " 2 - Gerer les references\n";
    cout << " 3 - Chercher une reference\n";
    cout << " 4 - Exporter en HTML\n";
    cout << " 5 - Parametres\n";
    cout << " 6 - Quitter\n";
    cout << "-------------------------------------\n";
    cout << "Votre choix : ";
}


bool executerAction(Menu etat, Bibliotheque & bibliotheque) {
    switch (etat) {
        case Menu::consulterreference:
            consulter_les_references(bibliotheque);
            break;
        case Menu::gererreferences:
            gerer_les_references(bibliotheque);
            break;
        case Menu::chercherreferences:
            chercher_une_reference(bibliotheque);
            break;
        case Menu::exporterenhtml:
            exporter_en_html(bibliotheque);
            break;
        case Menu::parametres:
            parametres(bibliotheque);
            break; 
        case Menu::quitterappli:
            return quitterApplication(bibliotheque);

        default:
            cout << "\nChoix invalide.\n";
            break;
    }
    return false; // continuer le programme
}



int main() {
    Menu etat = Menu::principal;
    string entree;
    Bibliotheque bibliotheque;
    string fichier;

    logo();
    cout << "=============================================\n";
    cout << "  BIENVENUE DANS L'APPLICATION BIBLIO \n";
    cout << "=============================================\n";
    cout << "Nom du fichier de la bibliotheque (.txt) : ";
    getline(cin, fichier);
    initialiser_projet(fichier, bibliotheque);
    while (true) {

        afficherMenu();
        cin >> entree;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (entree == "1")
            etat = Menu::consulterreference;
        else if (entree == "2")
            etat = Menu::gererreferences;
        else if (entree == "3")
            etat = Menu::chercherreferences;
        else if (entree == "4")
            etat = Menu::exporterenhtml;
        else if (entree == "5")
            etat = Menu::parametres;
        else if (entree == "6")
            etat = Menu::quitterappli;
        else {
            cout << "Choix invalide. Veuillez recommencer.\n";
            continue;
        }

        // Si executerAction retourne true, quitter la boucle
        if (executerAction(etat, bibliotheque)) {
            break;
        }
    }

cout << "\n Merci d'avoir utilise l'application. A bientot !\n";
    return 0;
}


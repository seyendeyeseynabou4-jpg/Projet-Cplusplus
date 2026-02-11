 //Pour au lieu d'utiliser filesystem on utilise directement fs 

// if (fs::is_regular_file(element)) C'est pour verifier si elemet est un  fichier

// else if (fs::is_directory(element)) Et la verifier si l'element est un dossier 



// int main(int argc, char* argv[]){
//     std::string chemin;
//     if(argc == 1){ //Aucun argument fourni juste le nom du document 
//         for (const auto& element : fs::directory_iterator(chemin)) {
//             // element représente chaque fichier ou sous-répertoire
//             std::cout << element.path().filename() << std::endl;
//         }
//     }
//     return 0;
// }

#include <iostream>     // Pour std::cout, std::cin, std::cerr
#include <filesystem>   // Pour manipuler fichiers et répertoires (C++17)
#include <iomanip>      // Pour std::setw, std::left (alignement des colonnes)

// Créer un alias court pour ne pas écrire std::filesystem à chaque fois
namespace fs = std::filesystem;

/*
 * Fonction : lister_repertoire
 * 
 * Rôle : Parcourir un répertoire et afficher son contenu avec des détails
 * 
 * Paramètre : chemin (string) - le chemin du répertoire à lister
 * 
 * Pourquoi cette fonction ? 
 * - Séparer la logique de listage du main() (bonne pratique)
 * - Pouvoir réutiliser cette fonction ailleurs si besoin
 * - Rendre le code plus lisible et organisé
 */
void lister_repertoire(const std::string& chemin) {
    
    // try-catch : Gérer les erreurs liées au système de fichiers
    // Pourquoi ? filesystem peut lancer des exceptions (permissions, fichier inexistant, etc.)
    try {
        
        // VÉRIFICATION 1 : Le chemin existe-t-il ?
        // fs::exists() retourne true si le chemin existe, false sinon
        // Pourquoi vérifier ? Éviter un crash si l'utilisateur donne un mauvais chemin
        if (!fs::exists(chemin)) {
            std::cerr << "Erreur : Le chemin '" << chemin << "' n'existe pas." << std::endl;
            return;  // Sortir de la fonction (ne pas continuer)
        }
        
        // VÉRIFICATION 2 : Est-ce bien un répertoire ?
        // fs::is_directory() retourne true si c'est un dossier, false si c'est un fichier
        // Pourquoi vérifier ? On ne peut pas "lister" un fichier, seulement un dossier
        if (!fs::is_directory(chemin)) {
            std::cerr << "Erreur : '" << chemin << "' n'est pas un répertoire." << std::endl;
            return;
        }
        
        // Afficher le chemin absolu (complet) du répertoire
        // fs::absolute() transforme un chemin relatif (.) en chemin complet (/home/user/...)
        // Pourquoi ? Pour que l'utilisateur sache exactement quel dossier est listé
        std::cout << "\nContenu de : " << fs::absolute(chemin) << "\n" << std::endl;
        
        // Afficher l'en-tête du tableau (colonnes)
        // std::left : aligner le texte à gauche
        // std::setw(N) : réserver N caractères de largeur pour la colonne
        // Pourquoi ? Créer un affichage propre et aligné comme une vraie commande ls
        std::cout << std::left 
                  << std::setw(6) << "Type"           // Colonne 1 : [F] ou [D]
                  << std::setw(18) << "Taille"        // Colonne 2 : taille en octets
                  << "Nom" << std::endl;              // Colonne 3 : nom du fichier/dossier
        
        // Ligne de séparation (60 tirets)
        // std::string(60, '-') crée une chaîne de 60 caractères '-'
        // Pourquoi ? Améliorer la lisibilité du tableau
        std::cout << std::string(60, '-') << std::endl;
        
        // BOUCLE PRINCIPALE : Parcourir tous les éléments du répertoire
        // fs::directory_iterator(chemin) : itérateur qui parcourt chaque élément
        // const auto& : type automatique par référence constante (efficace)
        // Pourquoi directory_iterator ? C'est LA fonction qui liste le contenu d'un dossier
        for (const auto& element : fs::directory_iterator(chemin)) {
            
            // Variables pour stocker le type et la taille
            std::string type;    // [F], [D] ou [?]
            std::string taille;  // Taille en octets ou "<DIR>"
            
            // VÉRIFICATION DU TYPE : Fichier normal ?
            // fs::is_regular_file() retourne true si c'est un fichier classique
            // Pourquoi ? Pour différencier les fichiers des dossiers (demandé dans l'énoncé)
            if (fs::is_regular_file(element)) {
                type = "[F]";  // F pour File (Fichier)
                
                // fs::file_size() retourne la taille en octets (unsigned long)
                // std::to_string() convertit le nombre en chaîne de caractères
                // Pourquoi file_size ? L'énoncé demande d'afficher la taille des fichiers
                taille = std::to_string(fs::file_size(element)) + " octets";
            } 
            // Sinon, est-ce un répertoire ?
            // fs::is_directory() retourne true si c'est un dossier
            else if (fs::is_directory(element)) {
                type = "[D]";     // D pour Directory (Répertoire)
                taille = "<DIR>"; // Les dossiers n'ont pas de taille simple à afficher
            } 
            // Sinon, c'est autre chose (lien symbolique, fichier spécial, etc.)
            else {
                type = "[?]";  // Type inconnu
                taille = "---";
            }
            
            // AFFICHAGE DE LA LIGNE
            // element.path() : chemin complet de l'élément
            // .filename() : extrait juste le nom (sans le chemin)
            // .string() : convertit en std::string
            // Pourquoi filename() ? On veut juste le nom, pas tout le chemin
            std::cout << std::left 
                      << std::setw(6) << type                           // Type : [F] ou [D]
                      << std::setw(18) << taille                        // Taille
                      << element.path().filename().string() << std::endl; // Nom
        }
        
        std::cout << std::endl;
        
    } 
    // Attraper les erreurs spécifiques au filesystem
    // filesystem_error : erreurs comme "permission refusée", "fichier inexistant", etc.
    // Pourquoi catch ? Éviter que le programme crash et afficher un message d'erreur clair
    catch (const fs::filesystem_error& e) {
        std::cerr << "Erreur filesystem : " << e.what() << std::endl;
    }
    // Attraper toutes les autres erreurs possibles
    catch (const std::exception& e) {
        std::cerr << "Erreur inattendue : " << e.what() << std::endl;
    }
}

/*
 * Fonction : main
 * 
 * Rôle : Point d'entrée du programme
 * 
 * Paramètres :
 * - argc (int) : nombre d'arguments passés en ligne de commande (minimum 1)
 * - argv (char*[]) : tableau contenant les arguments
 *   argv[0] = nom du programme (ex: "./myls")
 *   argv[1] = premier argument (ex: "/home/user")
 * 
 * Pourquoi ces paramètres ?
 * - Permettre à l'utilisateur de spécifier un chemin : ./myls /home
 * - Ou d'utiliser le répertoire courant : ./myls
 */
int main(int argc, char* argv[]) {
    
    // Variable pour stocker le chemin du répertoire à lister
    std::string chemin;
    
    // VÉRIFICATION DES ARGUMENTS
    
    // argc == 1 signifie : aucun argument fourni (juste le nom du programme)
    // Exemple : ./myls
    // Pourquoi cette vérification ? L'énoncé demande de lister le répertoire courant si pas d'argument
    if (argc == 1) {
        // "." représente le répertoire courant (là où on exécute le programme)
        // On aurait pu aussi utiliser : fs::current_path().string()
        // Pourquoi "." ? C'est plus simple et fonctionne sur tous les systèmes (Linux, Windows, Mac)
        chemin = ".";
        std::cout << "Aucun argument fourni. Listage du répertoire courant..." << std::endl;
    } 
    // argc == 2 signifie : un argument a été fourni
    // Exemple : ./myls /home/user
    else if (argc == 2) {
        // argv[1] contient le premier argument (le chemin)
        // Pourquoi argv[1] ? argv[0] est toujours le nom du programme
        chemin = argv[1];
        std::cout << "Listage du répertoire spécifié..." << std::endl;
    } 
    // argc > 2 signifie : trop d'arguments
    // Exemple : ./myls /home /user (on n'en attend qu'un seul)
    else {
        // Afficher un message d'aide pour expliquer l'utilisation correcte
        // argv[0] affiche le nom du programme utilisé
        // Pourquoi ce message ? Guider l'utilisateur si il se trompe
        std::cerr << "Usage : " << argv[0] << " [répertoire]" << std::endl;
        std::cerr << "  Sans argument : liste le répertoire courant" << std::endl;
        std::cerr << "  Avec argument : liste le répertoire spécifié" << std::endl;
        return 1;  // return 1 = code d'erreur (le programme s'est terminé anormalement)
    }
    
    // Appeler la fonction qui fait le vrai travail
    // Pourquoi une fonction séparée ? Rendre le main() simple et lisible
    lister_repertoire(chemin);
    
    // return 0 = code de succès (tout s'est bien passé)
    // Pourquoi retourner 0 ? Convention en C/C++ : 0 = succès, autre = erreur
    return 0;
}
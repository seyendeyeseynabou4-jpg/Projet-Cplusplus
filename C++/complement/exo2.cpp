#include <iostream> 
#include <fstream> 
#include <string>





// Un **flux** (stream en anglais) = un "canal" par lequel les données circulent, comme un tuyau.

// ### Les flux en C++ :

// **Flux d'entrée (`istream`)** = données qui **entrent** dans ton programme
// - `cin` : lit depuis le clavier
// - `ifstream` : lit depuis un fichier

// **Flux de sortie (`ostream`)** = données qui **sortent** de ton programme  
// - `cout` : affiche à l'écran
// - `ofstream` : écrit dans un fichier


using namespace std;

int main(){

    //Creer un fichier nom_du_fichier.txt que l'on peut manipuler en utilisant la variable mon_fichier

    ofstream mon_fichier("nom_du_fichier.txt"); //Associe le nom du fichier a la variable de flux

    mon_fichier << "Cette phrase est ecrite dans le fichier." <<endl;

    //Ecrire dans un fichier qui a le nom nom_du_fichier que l'on manipule en utilisant la variable mon fichier
    ifstream monfichier ("nom_du_fichier.txt"); //Associe le nom du fichier a la variable de flux 
    string un_mot ;

    utiliser la variable pour entrer dans le fichier nom_du_fichier et y lire un_mot
    monfichier >> un_mot ; //Lire un mot depuis le fichier.
    cout << un_mot << endl;  //Lis jusqu'au espace


        //POUR LIRE TOUS LE FICHIER LIGNE PAR LIGNE
    string ligne_complet ;
    while(getline(monfichier, ligne_complet)){ //ON MET TOUT LE CONTENU DE MONFICHIER ET ON LE MET DS LIGNE_COMPLET 
        cout << ligne_complet << endl;
    }


    string nomfichier = "nom_du_fichier.txt";
    ifstream fichier(nomfichier); //ouvrir le fichier

    if(fichier.is_open()) //Est-il possible de lire dans le fichier?

    {
        double valeur;
        fichier >> valeur; //Lire une valeur reel 
    }
    else 
        cerr <<"Impossible d'ouvrir le fichier \"" << nomfichier << "\"." << endl; //cerr c'est pour afficher des messages d'erreur
    return 0;
    // Ici la variable mon_fichier est detruite et le fichier automatiquement referme
}


#include <filesystem>

Opération	Utilité
exists()	Tester si un fichier ou un répertoire existe.

file_size()	Connaître la taille d'un fichier.

create_directory()	Créer, et remove() pour supprimer, des répertoires.

directory_iterator	Lister tous les fichiers et sous-répertoires dans un répertoire.

temp_directory_path()	Trouver le chemin du répertoire temporaire du système.


fs::current_path(): Obtient le répertoire courant

fs::directory_iterator(chemin)Parcourt les éléments d'un répertoire

fs::is_regular_file(element)Vérifie si c'est un fichier

fs::is_directory(element)Vérifie si c'est un répertoire

fs::file_size(element)Obtient la taille d'un fichier (en octets)

Indépendance de la Plateforme

if (fs::is_regular_file(element)) C'est pour verifier si elemet est un  fichier

else if (fs::is_directory(element)) Et la verifier si l'element est un dossier 

Le point le plus important : l'un des objectifs principaux de la bibliothèque
 <filesystem> est de fournir une interface unifiée et portable pour ces opérations.

    Oui, elle fonctionne de la même manière, que vous soyez sur Windows, macOS, Linux ou tout autre système supporté.

    Elle agit comme une couche d'abstraction : le code C++ que vous écrivez reste le même, et la bibliothèque 
    se charge de traduire vos commandes en appels spécifiques 
    au système d'exploitation sous-jacent (comme les appels aux APIs Win32 sur Windows ou les fonctions POSIX sur Linux/macOS).


#include <filesystem> 
namespace fs = std::filesystem; // On crée un alias 'fs'

// Ensuite, on utilise 'fs' :
if (fs::exists("mon_fichier.txt")) {
    // ...


Le rôle de stem()

La fonction stem() est une méthode fondamentale de la classe std::filesystem::path.
 Elle est utilisée pour extraire le nom de base d'un fichier, en excluant son extension.

C'est utile lorsque vous souhaitez manipuler un fichier sans vous soucier de son type (son extension).
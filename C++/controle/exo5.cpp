#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>


using namespace std;
namespace fs = std::filesystem;

struct Ville {
    string nom;
    size_t population;
    string departement;
    string region;
};

vector<Ville> lecture_fichiers(const fs::path& dirname)
{
    vector<Ville> villes;
    // À compléter...
    ofstream ofs(dirname);
    ifstream monfichier(dirname);
    if(monfichier.is_open()){
        
        Ville valeur;
        getline(monfichier,valeur.nom);
        getline(monfichier, valeur.departement);
        getline(monfichier,valeur.region);
        monfichier >> valeur.population;
        while(monfichier){
            villes.push_back(valeur);
        }
    }
    else
        cerr << "Impossible d'ouvrir le fichier" << std::endl;

    

    return villes;
}

size_t total_population_villes(const vector<Ville>& villes)
{

    // À compléter...
    size_t somme=0;
    Ville personnes;
    for(size_t i=0; i < villes.size(); i++){
        somme+= personnes.population;
    }
    return somme;
}


bool comparateur_villes(const Ville& a,const Ville& b)
{
    // À compléter...
}


void trier_villes(vector<Ville>& villes)
{

    // sort(villes.end(), villes.begin());
}

void ecrire_csv(const vector<Ville>& villes,const fs::path& resultat)
{
    // À compléter...
}

int main(int argc, char* argv[])
{
    vector <Ville> villes;
    fs::path dirname((argc == 2 ? argv[1] : "None")); // S'il y a bien une chaîne en paramètre, l'utiliser pour initialiser dirname.
    size_t nbre = total_population_villes(villes);
    cout << "les habitants total sont:" << nbre << endl;
    if(fs::is_directory(dirname))
    {
        vector<Ville> villes = lecture_fichiers(dirname);
        if(villes.size()==0)
            cout << "Vous n'avez chargé aucune ville !" << endl;
        else
        {
            trier_villes(villes);

            fs::path resultat = fs::temp_directory_path() / "villes.csv";
            cout << "Écriture du fichier de résultat dans " << resultat << "." << endl;
            ecrire_csv(villes,resultat);

            cout << "Vous avez traité " << villes.size() << " villes pour une population urbaine totale de " << total_population_villes(villes) << "." << endl <<
                    "La plus peuplée est : " << villes[0].nom << " avec ses " << villes[0].population << " habitants en région " << villes[0].region << " (code département : " << villes[0].departement << ")." << endl <<
                    "La moins peuplée est : " << villes[villes.size() - 1].nom << " avec ses " << villes[villes.size() - 1].population << " habitants en région " << villes[villes.size() - 1].region << " (code département : " << villes[villes.size() - 1].departement << ")." << endl;
        
                }
    }
    else
    {
        cerr << "Merci d'indiquer en paramètre du programme le chemin du répertoire « Population » fourni et comportant les données, par exemple :" << endl
             << argv[0] << " /tmp/exo5/Population" << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

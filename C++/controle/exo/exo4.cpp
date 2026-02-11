#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

struct Fiche {
    string nom,prenom;
    double taille;
    bool fille;
    string commentaire;
    string image;
};

istream& chargeUneFiche(istream& ifs,Fiche& f)
{
    getline(ifs,f.nom);
    getline(ifs,f.prenom);
    char c='X';
    ifs >> f.taille >> c;
    f.fille = (c=='F');
    getline(ifs >> ws, f.commentaire);
    getline(ifs,f.image);
    return ifs;
}

ostream& afficheUneFiche(ostream& ofs,const Fiche& f)
{
    ofs << f.nom << ", " << f.prenom << endl
        << '\t' << f.taille << "m " << (f.fille?"Femme":"Homme") << endl
        << "\tCommentaire : " << f.commentaire << endl
        << "\tFichier image : " << f.image << endl;
    return ofs;
}

ostream& sauveUneFiche(ostream& ofs,const Fiche& f)
{
    ofs << f.nom << endl
        << f.prenom << endl
        << f.taille << ' ' << (f.fille?'F':'H') << endl
        << f.commentaire << endl
        << f.image << endl;
    return ofs;
}

ostream& exporteUneFicheCSV(ostream& ofs,const Fiche& f)
{
    ofs << f.nom << ";" << f.prenom << ";" << f.taille << " " << (f.fille?'F':'H') << ";" << "(" << f.commentaire << ")" << ";" << f.image << endl;
    return ofs;
}

ostream& exporteUneFicheHTML(osteam& ofs,const Fiche& f)
{
    ofs << "<div class=\"fiche\">\n"
        << "\t<h2>" << f.nom << ", " << f.prenom << "</h2>\n"
        << "\t<p>Taille : " << f.taille << "m " << (f.fille?"Femme":"Homme") << "</p>\n"
        << "\t<p>Commentaire : " << f.commentaire << "</p>\n"
        << "\t<img src=\"" << f.image << "\" alt=\"Photo de " << f.prenom << " " << f.nom << "\">\n"
        << "</div>\n";
    return ofs;
}

void chargeAnnuaire(vector<Fiche>& fiches,fs::path& fname)
{
    ifstream monfichier(fname);
    if(!monfichier.is_open())
    {
        cerr << "Impossible d'ouvrir le fichier " << fname << endl;
        return;
    }
    while(monfichier)
    {
        Fiche f;
        chargeUneFiche(monfichier,f);
        fiches.push_back(f);
    }
}

ostream& afficheAnnuaire(const vector<Fiche>& fiches,ostream& ofs)
{
    for(size_t i=0;i<(fiches.size()-1);++i)
    {
        ofs << "Fiche #" << (i+1) << " :" << endl;
        afficheUneFiche(ofs,fiches[i]);
    }
    return ofs;
}

void sauveAnnuaire(const vector<Fiche>& fiches,fs::path& fname)
{
    ofstream monfichier(fname);
    if(!monfichier.is_open())
    {
        cerr << "Impossible d'ouvrir le fichier " << fname << endl;
        return;
    }else {
        for(size_t i=0;i<(fiches.size()-1);i++)
            sauveUneFiche(monfichier,fiches[i]);
    }
}

void exporteAnnuaireCSV(const vector<Fiche>& fiches,fs::path& fname)
{
    ofstream monfichier(fname);
    if(!monfichier.is_open())
    {
        cerr << "Impossible d'ouvrir le fichier " << fname << endl;
        return;
    }
    monfichier << "Nom;Prenom;Taille Et Sexe;Commentaire;Photo Path" << endl;
    for(size_t i=0;i<(fiches.size()-1);i++)
        exporteUneFicheCSV(monfichier,fiches[i]);
}

void exporteAnnuaireHTML(const vector<Fiche>& fiches,fs::path& fname)
{
    ofstream monfichier(fname);
    if(!monfichier.is_open())
    {
        cerr << "Impossible d'ouvrir le fichier " << fname << endl;
        return;
    }
    monfichier << "<!DOCTYPE html>\n<html>\n<head>\n\t<title>Annuaire</title>\n</head>\n<body>\n";
    for(size_t i=0;i<(fiches.size()-1);i++)
        exporteUneFicheHTML(monfichier,fiches[i]);
    monfichier << "</body>\n</html>\n";
}

void ajouteFiche(vector<Fiche>& fiches)
{
    Fiche f;
    cout << "Nom ?>";
    getline(cin,f.nom);
    cout << "Prénom ?>";
    getline(cin,f.prenom);
    cout << "Taille ?>";
    cin >> f.taille;
    cout << "Homme (H) ou femme (F) ?>";
    char c='X';
    while(c!='H' && c!='F')
        cin >> c;
    f.fille = (c=='F');
    getline(cin,f.commentaire); // Nécessaire pour vider les caractères de la ligne précédente
    cout << "Commentaire ?>";
    getline(cin,f.commentaire);
    cout << "URL d'une image ?>";
    getline(cin,f.image);
    fiches.push_back(f);
}

void supprimeFiche(vector<Fiche>& fiches)
{
    cout << "Numéro de la fiche à supprimer ? (0 pour annuler) >";
    size_t num=0;
    cin >> num;
    if(num==0)
        cout << "Annulation" << endl;
    else if(num<=fiches.size())
        fiches.erase(fiches.begin()+(num-1));
    else
        cout << "Numéro de fiche invalide. Abandon." << endl;
}

char menu()
{
    cout <<
    " q - quitter en sauvegardant l'annuaire" << endl <<
    " Q - quitter sans sauvegarder l'annuaire" << endl <<
    " a - afficher l'annuaire" << endl <<
    " + - ajouter une fiche à l'annuaire" << endl <<
    " - - supprimer une fiche de l'annuaire" << endl <<
    " C - exporter l'annuaire au format CSV" << endl <<
    " H - exporter l'annuaire au format HTML" << endl <<
    "Votre choix ? >";
    char c='X';
    cin >> c;
    cin.ignore(999999,'\n'); // Sauter tout caractère saisi après le choix et jusqu'au caractère Entrée inclus.
    return c;
}

int main()
{
    fs::path fname     = fs::current_path() / "exo4" / "MonAnnuaire.txt";
    fs::path fnamecsv  = fs::current_path() / "exo4" / "MonAnnuaire.csv";
    fs::path fnamehtml = fs::current_path() / "exo4" / "MonAnnuaire.html";
    vector<Fiche> fiches;
    chargeAnnuaire(fiches,fname);
    char choix;
    do
    {
        choix = menu();
        switch(choix)
        {
            case 'q':
                sauveAnnuaire(fiches,fname);
            case 'Q':
                break;
            case 'a':
                afficheAnnuaire(fiches,cout);
                cout << endl;
                break;
            case '+':
                ajouteFiche(fiches);
                break;
            case '-':
                supprimeFiche(fiches);
                break;
            case 'C':
                exporteAnnuaireCSV(fiches,fnamecsv);
                cout << "Export CSV effectué dans " << fnamecsv << "." << endl;
                break;
            case 'H':
                exporteAnnuaireHTML(fiches,fnamehtml);
                cout << "Export HTML effectué dans " << fnamehtml << "." << endl;
                break;
            default:
                cerr << "Choix inconnu ! Recommencez." << endl;
        }
    }
    while(choix!='q' && choix!='Q');

    return EXIT_SUCCESS;
}
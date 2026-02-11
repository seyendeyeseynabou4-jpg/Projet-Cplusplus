#ifndef EXO_HPP
#define EXO_HPP

        // For the first question 

struct date{
    unsigned short int  mois, jour, annee ; 
};
struct Fichier{
    std::string somme_SHA, nomfile ;
    date d ;

};

            // For the second question 

std::vector <Fichier> charger_fichier(const std::string &nomFichier);        
std::vector <std::string> split(std::string phrase, char sep = ' '); 

#endif
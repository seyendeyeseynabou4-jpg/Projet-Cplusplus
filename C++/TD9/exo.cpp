#include <iostream> 
#include <vector>
#include <string> 
#include <fstream>
#include "exo.hpp"





// std::vector <Fichier> charger_fichiers(const std::string &nomFichier){
//     std::vector <Fichier> v;
//     ifstream file (nomFichier);
//     if(file.is_open()){
//         std::string line;
//         while(getline(file,line)){
//             Fichier f;
//             std::vector<std::string> parties = split(line);   
//             std::erase(parties,' ');
//             f.sha = parties[1];
//             f.nom = parties[2];
//             std::vector<std::string> parties_0 = split(parties[0], '-');
//             f.date.jour = stoi(parties_0[0]);
//             f.date.mois = stoi(parties_0[1]);
//             f.date.annee = stoi(parties_0[2]);

//             v.push_back(f);
//         }
//     }
//     return v;
// }
std::vector <std::string> split(std::string phrase, char sep) {
    std::string mot; 
    std::vector <std::string> tab ; 
    for(char c:phrase){
        if(c != sep)
            mot+=c; 
        else{
            tab.push_back(mot);
            mot = " "; 
        }
        tab.push_back(mot);
        
    }
    return tab ;
}


// OKI MADEMOISELLE MTNT POUR TESTER TA COMPREHEHNSION REPRENDS LE CODE SANS REGARDER LA CORRECTION TEBE K T'ES

std::vector <Fichier> charger_fichier(const std::string &nomFichier){
    std::vector<Fichier> v ; 
    ifstream ifs(nomFichier); 

    char sep ;
    std::string f 
    if(ifs.is_open()){
        while(getline(ifs, line)){
            Fichier line ; 
            std::vector <std::string> Parties = split(f, sep); 
            // std::erase(line, ' ');
            line.somme_SHA = Parties[1]; 
            line.nomfile = Parties[3]; 
            std::vector <std::string> Parties_0 = split(Parties[0], '-') ; 
            line.d.jour = stoi(Parties_0[0]) ; 
            line.d.mois = stoi(Parties_0[1]); 
            line.d.annee = stoi(Parties_0[2]);

            v.push_back(line); 
        }
    }
    return v ; 
}


#include <iostream> 
#include <vector> 
#include "exo1.hpp"

   void remplace_voyelle_minuscule(std::string &s){
    switch(s){
        case 'a':
            s='1';
            breack;
        case 'e':
            s='2';
            breack;
        case 'i':
            s='3';
            breack;
        case 'o':
            s='4';
            breack;
        case 'u':
            s='5';
            breack;
    }
   }

    std::string concatenation(const std::vector<std::string> &v){
     std::string resultat;
     for(const auto &str : v){
          resultat += str;
     }
     return resultat;
    }
   bool verification_mot( const std::string &s){
     std::string mot=concatenation(s);
        if(mot == s)
            return true;
        else
            return false;
   }
   std::vector <string> delete_espace( std::string &s){ 
    std::vector <string> tab;
    std::string mot;
    for(size_t i=0; i<s.size(); i++){
        if(s[i]!=' '){
            mot+=s[i];
        }
        else{
            tab.push_back(mot);
            mot="";
        }
    }
    tab.push_back(mot);
    return tab;
   }

#ifndef GERERBIBLIOTHEQUE_HPP
#define GERERBIBLIOTHEQUE_HPP
#include "bibliotheque.hpp"





std::string titreSansArticle(const std::string &titre); 
void consulter_les_references(const Bibliotheque & bibliotheque) ;
void gerer_les_references(Bibliotheque & bibliotheque ); 
void chercher_une_reference(Bibliotheque & bibliotheque);
void exporter_en_html(const Bibliotheque & bibliotheque);
void parametres(Bibliotheque & bibliotheque);

void ajouterLivre(Bibliotheque &bibliotheque) ;
void gerer_les_references(Bibliotheque &bibliotheque) ;
void importerDepuisCSV(Bibliotheque &bibliotheque) ;
bool quitterApplication(Bibliotheque &bibliotheque) ; 
#endif 
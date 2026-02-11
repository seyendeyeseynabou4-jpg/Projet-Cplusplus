#include <iostream>
#include "Polynome.hpp"
#include <string>


void stockPolynome(Polynome *p[]){
    for(size_t  i = 0; i < 10 ; i++){
        std::cout << '['<< i << ']' ;
        if(p[i] == nullptr)
            std::cout << ":vide"; 
        else 
            std::cout << *p[i] ;
    std::cout << std::endl;    
    }
}

int main() {
    Polynome* tab[10] = {nullptr};
    int choix = -1 ; 
    unsigned int emplacement ; 
    unsigned int indice, d; 
    unsigned int emplacement1, emplacement2 ; 



    while (choix != 0)
    {
        stockPolynome(tab); 
        std::cout << "Quelle action voulez-vous faire? (1.Saisir 2.Additionner 3.Soustraire 4.Deriver 5.Afficher 0 Quitter): " << std::endl;
        std::cin >> choix; 

        if(choix == 1){
            // unsigned int indice, d; 
            std::cout << "Donnez l'indice(0-9)> ";
            std::cin >> indice; 
            std::cout << "Degre > ";
            std::cin >> d;
            double *coefs = new double [d +1 ];
            for(size_t i = 0  ; i < d+1; i++){
                std::cout << "coefs x^" << i << "> " ;
                std::cin >> coefs[i]; 
            }
            if(tab[indice] != nullptr){
                delete tab[indice]; 
                tab[indice] = nullptr;
            }

            tab[indice] = new Polynome(d, coefs); 
            delete [] coefs; //supprimer le tableau pour eviter les fuites de memoire
            
        }

        // Faire la somme de deux polynomes 
        // A AMELIORER ET FAIRE DE SORTE QUE L'UTILISATEUR PUISSE FAIRE LA SOMME DE PLUSIEURS POLYNOMES
        // IDEM POUR LA DIFFERENCE

        else if(choix == 2){
            // unsigned int emplacement1, emplacement2 ; 
            std::cout << "Donnez l'emplacement du premier polynome:" ;
            std::cin >> emplacement1;
            // if(tab[emplacement1]== nullptr)
                // std::cout << "L'emplacement " << emplacement1 << " est vide."<<std::endl;

            std::cout <<"Donnez l'emplacement du deuxieme polynome: ";
            std::cin >> emplacement2;
            if(tab[emplacement2]== nullptr || tab[emplacement1] == nullptr){
                std::cout << "L'emplacement est vide"<<std::endl;
                continue;

            }
            Polynome p = *tab[emplacement1] + *tab[emplacement2];
            std::cout << "(p1+p2)(x)= " << p <<std::endl;   
            std::string reponse; 
            std::cout << "Voulez-vous stocker le resulat dans le tableau?";
            std::cin >> reponse;
            if(reponse == "oui"){
                // unsigned int emplacement ; 
                std::cout << "Dans quel emplacement voulez-vous mettre le resultat>" ;
                std::cin >> emplacement; 
                if(tab[emplacement] != nullptr)
                    delete tab[emplacement];
                
                tab[emplacement] = new Polynome(p);

            }


        }


        else if(choix == 3){
            // unsigned int emplacement1, emplacement2 ; 
            std::cout <<"Donnez l'emplacement du premier polynome:";
            std::cin >> emplacement1 ; 
            std::cout <<"Donnez l'emplacement du deuxieme polynome: ";
            std::cin >> emplacement2;
            if(tab[emplacement1] == nullptr || tab[emplacement2]== nullptr) {//Verifier si l'emplacement n'est ps vide pour eviter les plantages 
                std::cout << "L'emplacement " << emplacement1 << " est vide"<< std::endl; 
                continue; 
            }
            // if(tab[emplacement2]== nullptr)
                // std::cout << "L'emplacement " << emplacement2 << " est vide"<<std::endl;
            std::cout << "(p1-p2)(x)= " << *tab[emplacement1] - *tab[emplacement2] <<std::endl;  //* pour prendre les variables cad les polynomes et non leurs adresses 
   
        }


        else if(choix == 4){
            // unsigned int emplacement ; 
            std::cout << "Donnez l'emplacement du polynome que vous-voulez derive> " ;
            std::cin >> emplacement ; 
            if(tab[emplacement] == nullptr){
                std::cout << "Il n'ya pas de polynome dans l'emplacement que vous avez saisi" << std::endl; 
                continue; 
            }

            std::cout << "Le polynome p(x) = " << *tab[emplacement] ;
            Polynome pprime(tab[emplacement]->deriver() ); // -> combinaison de. et * donc on ne met pas de *devant tab 
            std::cout << "a pour deriver p'(x)= " << pprime << std::endl;
        
        }


        else if(choix == 5){
            std::cout << "Donnez l'emplacement du polynome que vous voulez affiches> "; 
            std::cin >> emplacement ; 
            if(tab[emplacement] == nullptr){
                std::cout << "Il n'ya pas de polynome dans l'emplacement que vous avez saisi" << std::endl; 
                continue; 
            }
            
            std::cout << "Le polynome est p(x)= " << *tab[emplacement] << "et son degre est:" << tab[emplacement]->getDegre()<< std::endl; 

        }
        else if(choix == 0){
            std::cout << "A bientot!" << std::endl; 
        }
        else
            std::cout <<"Veuillez saisir un numero entre 0-5:" << std::endl; 
    
        }

        //Liberer toute l'espace allouer avant de quitter le programme
        for(size_t i = 0 ; i<10; i++){
            if(tab[i] != nullptr)
                delete tab[i];
        }


    return 0; 
}
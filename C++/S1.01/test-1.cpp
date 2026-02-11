#include <iostream>
#include <string>
#include <vector>


 
//Ce qui doit etre dans le fichier hpp

struct Livre{          //Structure pour regrouper les elements du livre 
    std::string auteur;
};

struct bibliotheque{    //Structure pour regrouper les elements de la biblotheque 
    std::string titre;
    std::string description ;
    std::vector <Livre> livres;
};

void page_precedente(){
    menu();
}

void page_suivant() {
    std::cout << "Pas encore dispo !!!!" << std::endl;
}
//Une fonction booleen qui sera charge de demander a l'utilisateur sur quel page 
//il veut naviguer ( "page suivante" / "page precedente ")



void consulter_les_references(){   ///Fonction pour consulter les references 
    unsigned int choix;
    bibliotheque resume;
    // std::vector <Livre> livres;   A Revoir prsk je ne suis pas sur de ce que j'ai fais
    for(size_t i=0; i < livres.size(); i++){
        std::cout << livres[i] << std::endl;
        std::cout << resume.description << std::endl; 
        std::cout << resume.titre << std::endl;
    }
    std::cout << choix ;
    std::cout << "Bienvenu c'etatit juste un test " << std::endl ;
    std::cout << "Now voulez vous toujours continuer l'aventure ?> " << std::endl;
    std::cout << "1 pour aller a la page suivante et 0 pour quitter";  
    std::cin >> choix ;
    if(choix == 1)
        page_suivant() ;
    else if(choix == 0)
        page_precedente();
    else 
        std::cout << "Choix indisponible pour le moment" << std::endl;


}
void menu(){

    unsigned int choix ;
    std::cout << "Menu principal" << std::endl; 
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Dans quel rubrique voudriez-vous allez? " << std::endl;
    std::cout << "Votre choix> " ;
    std::cin >> choix;
    if(choix == 1)
        consulter_les_references();
    else 
        std::cout << "Desolee mais le choix que vous avez saisi n'est pas encore dispo" << std::endl;
}





//Fonction pour afficher les images ASCI 
void logo(){
    std::cout << R"(
    
         __                                          
              ,_  :  \                                         
              ; L_;   ;.                                      
              `.' `   ` \                                      
             ,'          ;
             ; ",        |
           .-' *         |
          $    _         ;_                                   
           \   ;      _.-' )                                   
            `+*     .'   -')
     [bug]   .`._.-'      /                                    
            ,(      .-   :                                     
         _.: ; -'.'     `,                                    
   /\--*"   \/  .'     ;  ;                                    
  /  \      /-.-'"*.  /    \
 ;__.-*"\.--*"      ;:_..-+'                                   
 \\     :       _.-'       ;                                   
  \\    *.___.-'           :
 .-\\      \               |                                   
: ;.-.      \-*""*.        ;                                  
: : ; ; _.-*"      ;      /                                    
 Y: : '"           ,___.-'                                     
   Y'  __...___.-*"
    `"'
    
    )" << std::endl;
}

int main(){
    logo();
    menu();
}
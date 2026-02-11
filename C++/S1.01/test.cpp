#include <iostream>
#include <string>



//Fonction pour afficher les images ASCI 
void des(){
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

//Fonction qui demande à l'utilisateur de choisir là ou il veut aller
void saisi_choix(){
    unsigned int choix;
    do{
        std::cout << "> Votre choix : " ;
        std::cin >> choix ;
        if(choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 && choix != 6){
            std::cout << "Le chiffre que vous avez choisi n'est pas valide : " << std::endl;
            std::cout << "Veuillez donner un nombre soit 1, 2, 3, 4, 5 ou 6 qui depend de vos choix: " ; 
            std::cin >> choix;
        }


    }while(choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 && choix != 6);
}

// J'ai deja crée une page html qui affiche pour l'instant les listes qui sont
// dans le menu principal , mais je ne sais pas comment combiner les deux codes 

// Bon je vais esssayer d'abord le truc du istream

// void meunu_principal() {

// }


//Mais trés cher ls fstream c'est pas pour lire des fichiers?????? Donc tu veux dire que html n'est pas un fichier?
//Si mais les extensions ne sont pas ls memes. Pas faux et si on essayais de changer l'extension? 
//Aucune idée essaye pour voire si ça va marcher d'abord 

//Navré de te decevoir mais le truc de fstream c'est pour mire et ecrire dans le fichier pas
//de les executer ouplaaa



//Fonction qui permet  d'utiliser le fichier html dans le code .cpp(C'est ce que je pensais frR )
// void combinaison_html_et_css(){

//     std::string line_complet ; 
//     std::ifstream menu("test.html"); 
//     menu >> line_complet ; 
//     std::cout << line_complet << std::endl ; 
//     std::cout << "Navré de vous decevoir mais ce que vous  voulez faire n'est pas possible!!!" << std::endl; 
// }

int main(){
    des();
    std::cout << "Menu principal" << std::endl; //Pour afficher le menu principal que l'on peut personnaliser avec html
    std::cout << "------------------------------------------------------" << std::endl ; 
    combinaison_html_et_css(); 
    saisi_choix(); 
    return 0;
}


//Une page web permettant d'afficher le menu principal
//La page a pour nom: test.html

//C'est cette page qui va nous permettre de circuler dans l'application 

//Mais le probleme est comment on va faire pour utiliser de html a l'interieur de notre code 


//Bon bah je te suggére de faire les autres en attendant 







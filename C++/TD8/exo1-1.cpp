#include <iostream> 



int nombre_de_couleurs(int nb){
    while(nb > 8){
        std::cout << "Erreur : vous ne pouvez pas saisir plus de 8 couleurs." << std::endl ;
        std::cout << "Entrer le nombre de couleurs à saisir>";
        std::cin>> nb;
    }
    return nb;
}

void verification( std::string msg){
    size_t couleur
    do{
        std::cout <<msg ;
        std::cin >>couleur;
        if(couleur > 255){
            std::cout << "Erreur: cette valeur n'est pas permise." << std::endl;
            std::cout <<"Vous devez saisi un nombre qui est sur l'intervalle [0,255]." << std::endl;
            std::cin >> couleur;
        }

     }while(couleur > 255);
}

RGB demander_couleur(){
    RGB c ;
    c.r=
}

int main(){
        size_t couleur=0;
        int nb=0;
        std::cout << "Entrer le nombre de couleurs à saisir> " ;
        std::cin >> nb;
        nombre_de_couleurs(nb);
        for(int i=0 ; i<nb; i++){
            std::cout << "saisissez la valeur de la couleur " << i+1 <<"(R, G, B):" <<std::endl;
        }
        
        
         

}
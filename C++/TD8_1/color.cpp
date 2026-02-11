#include <iostream>
#include <vector>

struct RGB{
    unsigned char r, g, b;
};




// SAISIR LES VALEURS DES COULEURS
unsigned char verification(const std::string &msg){
    unsigned int  value;
    do{
        // std::cout << "Saisissez la couleur " << std::endl;
        std::cout << msg; 
        std::cin>> value;
        if(value > 255){
            std::cout << "Erreur : cette valeur n'est pas permise."<<std::endl;
            std::cout << "Vous devez saisir un nombre sur l'intervalle [0,255]." << std::endl;
      
            std::cout << msg;
            std::cin>> value;
        }
        
    }while (value > 255);

    return (unsigned char)(value);
    

}

void readcolor(RGB &rgb){
    rgb.r=verification("R> ");
    rgb.g=verification("G> ");
    rgb.b=verification("B> ");
}

void print(const std::vector <RGB> &colors){
    
    for(size_t i=0; i<colors.size(); i++){
        // std::cout << "Couleur " << i+1 << ":" << std::endl;
        // // unsigned int value = (unsigned int)(colors);
        std::cout << "RGB( " << colors[i]<< ")"<<std::endl; 
    }
    
}

// std::string rgb_to_hex(){
    
// }

int main(){
    RGB rgb;
    std::vector <RGB> colors;
    size_t nb_couleur;
    std::cout << "Entrer le nombre de couleurs a saisir>" ;
    std::cin >> nb_couleur;
    while(nb_couleur > 8){
        std::cout << "Erreur : vous ne pouvez pas saisir plus de 8 couleurs." << std::endl ;
        std::cout << "Entrer le nombre de couleurs a saisir> ";
        std::cin>> nb_couleur;
    }
    
    for(size_t i=0 ; i < nb_couleur; i++){
        std::cout << "Saisissez la couleur" << i+1 <<"(R, G, B) :" <<std::endl;
        readcolor(rgb);
        colors.push_back(rgb);
    }
    std::cout <<"==== Lisye des couleurs======" << std::endl;
    // print(colors);
    return 0;
}
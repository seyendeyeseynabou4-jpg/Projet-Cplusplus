#include <iostream> 
#include <fstream>
#include <vector>
#include <string>

// void demande_num_atomique(std::vector <double> v){
//     unsigned int num_atomique;
   
//         std::cout << "Donnez un numero atomique: ";
//         std::cin >> num_atomique;
//         while(num_atomique > v.size()){
//             if(num_atomique > v.size()){
//                 std::cout << "Erreur: Le numero que vous avez saisi est superieur a " << v.size() << ": " << std::endl;
//                 std::cout << "DOnnez un num inferieur ou egal a " << v.size() << ":" ;
//                 std::cin >> num_atomique; 
//             }
           
//         }
//         std::cout << v[num_atomique -1] << std::endl ;
        
    
// }



void demande_new_num_atomique(std::vector <double> v){
    unsigned int new_num_atomique;
    do{
        std::cout << "Donnez a nouveau un numero atomique ou 0 pour terminer le programme: ";
        std::cin >> new_num_atomique;
        while(new_num_atomique > v.size()){
            if(new_num_atomique > v.size()){
                std::cout << "Erreur: Le numero que vous avez saisi est superieur a " << v.size() << ": " << std::endl;
                std::cout << "DOnnez un num inferieur ou egal a " << v.size() << ":" ;
                std::cin >> new_num_atomique; 
            }
           
        }
        if(new_num_atomique == 0)
        {
            std::cout << "Le programme est termine " << std::endl;
            return ;
        }
        else

            std::cout << v[new_num_atomique] << std::endl;
       
        

    }while(new_num_atomique != 0);


}

//FONCTION PERMETTANT DE demander a l'utilisateur de choisir un nombre de lettre 

void nombre_lettre(std::vector <std::string> v){
    unsigned int nb_lettre;
    unsigned int compter=0;
    std::cout << "Donnez un nombre de lettre: " ;
    std::cin >> nb_lettre;
    for(size_t i=0; i < v.size(); i++){
        if(v[i].length() ==nb_lettre)  //length() est la meme chose que size()
            compter++;
    }
    std::cout << "Il y'a " << compter <<" Mots qui ont " << nb_lettre << " lettres. " << std::endl; 
}

//LA FONCTION APPEND PERMET D'AJOUTER DU TEXTE DANS UN FICHIER SANS SUPP SON CONTENU 

int main(){
    std::vector <std::string> v ; 
    std::string chaine; 
    std::ifstream lire_mot("liste_de_mots_francais-UTF8-LF.txt");
    if(!lire_mot.is_open()){
        std::cout << "Impossible d'ouvrir le fichier " <<std::endl ; 
        return  1;
    }
    while (getline(lire_mot, chaine)){
        v.push_back(chaine);
    }
    for(size_t i=0; i < v.size(); i++)
        std::cout << v[i] << std::endl;
    
    // std::ofstream ajout_mot("liste_de_mots_francais-UTF8-LF.txt", std::ios::app); // le ios::app permet d'ajuter du texte a la fin d'un fichier
    // ajout_mot << "anticonstitutionnellement" << std::endl;
    // ajout_mot << "intergouvernementalisations" << std::endl;
    // ajout_mot.close();
    nombre_lettre(v);
    
    return 0;
}
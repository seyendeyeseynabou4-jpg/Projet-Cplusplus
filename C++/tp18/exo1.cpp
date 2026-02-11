#include <iostream> 
#include <fstream>
#include <vector>
#include <string>

void demande_num_atomique(std::vector <double> v){
    unsigned int num_atomique;
   
        std::cout << "Donnez un numero atomique: ";
        std::cin >> num_atomique;
        while(num_atomique > v.size()){
            if(num_atomique > v.size()){
                std::cout << "Erreur: Le numero que vous avez saisi est superieur a " << v.size() << ": " << std::endl;
                std::cout << "DOnnez un num inferieur ou egal a " << v.size() << ":" ;
                std::cin >> num_atomique; 
            }
           
        }
        std::cout << v[num_atomique -1] << std::endl ;
        
    
}



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



int main(){
    std::vector <double> v ; 
    std::string chaine; 
    std::ifstream lire_masses_atomiques("MasseAtomiqueParElement.txt");
    if(!lire_masses_atomiques.is_open())
        std::cout << "Impossible d'ouvrir le fichier " <<std::endl ; 
    while (getline(lire_masses_atomiques, chaine))
    {
       v.push_back(stod(chaine));
    }
    for(size_t i=0; i < v.size(); i++)
        std::cout << v[i] << std::endl;
    demande_num_atomique(v) ;
    demande_new_num_atomique(v);
    
}
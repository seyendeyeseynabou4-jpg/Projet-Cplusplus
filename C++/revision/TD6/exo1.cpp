// #include <iostream> 
// #include <vector> 
// #include <string> 
// #include <algorithm>
// #include <set>

//             // 1er QUESTION
// std::vector <int> liste(){
//     std::vector <int> v ;
//     std::string s ;
//     std::cout << "Donnez une liste d'entier:" ;
//     while ( std::getline(std::cin , s)&& !s.empty()){
//         int nombre = std::stoi(s);
//         v.push_back(nombre);
//     }
//     return v;
// }


//             // 2eme QUESTION

// void afficher(const std::vector <int> &tab){
//     for(int i:tab)
//         std::cout << i << std::endl ;
// }


//                 // 3eme QUESTION
// void ordre_croissant(const std::vector <int> &v){
//     std::vector <int> tab=v;
//     std::sort(tab.begin(), tab.end());
//     afficher(tab);
// }



//                 // 4eme QUESTION

// void afficher_sans_doublon(const std::vector <int> &v){
//     std::vector <int> tab=v ;
//     std::sort(tab.begin(), tab.end());
//     int precedent = tab[0] + 1 ;
//     for (int i:tab){
//         if(precedent != i)
//             std::cout << i << std::endl ;

//         precedent = i ;
//     }
// }


//                 // AVEC UNIQUE ET ERASE 

// void afficher_sans_doublon_avec_unique(std::vector <int> &v){

//     std::sort(v.begin(),v.end());
//     std::vector <int>::iterator it = std::unique(v.begin(), v.end());
//     v.erase(it, v.end());
//     afficher(v); 
// }



//             // 5eme QUESTION


// void trier_with_set(std::vector <int> &v){

//     std::set <int> s(v.begin(), v.end());
//     // for(int i:v)
//     v.assign(s.begin(), s.end());    //remplace v par le contenu de S 
//     afficher(v);
// }

// int main(){
//     std::vector <int> v = liste();
//     // for (size_t i=0; i <= v.size(); i++){
//     //     std::cout << v[i] << std::endl ;
//     // }
//     std::cout << "Avant trie:" << std::endl ;
//     afficher(v);
//     std::cout << "Apres trie par ordre croissant:" << std::endl ;
//     ordre_croissant(v);
//     std::cout << "Apres supression des doublons:" << std::endl ;
//     afficher_sans_doublon(v);
//     std::cout << "Apres suppression des doublons avec unique et erase:" << std::endl;
//     afficher_sans_doublon_avec_unique(v);
//     std::cout <<"Trie avec set:" << std::endl ;
//     trier_with_set(v);

//     return 0;
// }


            // Reprenons l'exercice 1 pour etre sur que l'on a compris


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

std::vector <int> liste(){
    std::vector <int> v ;
    std::string s ;
    std::cout <<"Donnez une liste d'entier:" << std::endl;
    while (std::getline(std::cin, s ) && !s.empty()){
        int nombre = std::stoi(s);
        v.push_back(nombre);
    }
    return v;
}

void affichage(const std::vector <int> &tab){
    for(int i:tab)
        std::cout << i << std::endl ;
}

void trie_ordre_croissant(const std::vector <int> &v){
    std::vector <int> tab = v;
    std::sort(tab.begin(), tab.end());
    affichage(tab);
}

void afficher_sans_doublon(std::vector <int> &v){
    std::sort(v.begin(), v.end());
    int precedent = v[0] + 1 ;
    for (int i:v ){
        if( i!= precedent)
            std::cout << i << std::endl;
        precedent = i;
    }

}

void afficher_sans_doublon_avec_unique(std::vector <int> &v){
    std::sort(v.begin(), v.end());
    std::vector <int>::iterator it = std::unique(v.begin(), v.end());
    v.erase (it, v.end());
    affichage(v);
}


void trie_with_set(std::vector <int> &v){
    std::set <int> s(v.begin(), v.end());
    v.assign(s.begin(), s.end());
    affichage(v);
}

int main(){
    std::vector <int> v = liste();
    affichage(v);
    std::cout << "Apres trie par ordre croissant:" << std::endl ;
    trie_ordre_croissant(v);
    std::cout << "Apres supression des doublons : " << std::endl ;
    afficher_sans_doublon(v);
    std::cout << "Apres supression des doublons avec unique et erase: " << std::endl ;
    afficher_sans_doublon_avec_unique(v);
    std::cout << "Apres supression des doublons avec set " << std::endl ;
    trie_with_set(v);
    return 0;
}
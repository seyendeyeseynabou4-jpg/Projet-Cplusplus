// avant de commencer j'ai d'abord cree un fichier que j'ai nomme brouillon.cpp. Et dans ce fichier j'ai essaye
// de faire d'abord un trie normal comme vue en TD. Ensuite j'ai essaye de mesurer le temps d'execution de mon programme avant d'attaquer 
// la sae pour avoir en quelque sorte une idee de ce qui m'attends 

// swap (a, b ) pour echanger les valeurs de a et b : utiliser pour le trie a bulles

#include <iostream>
#include <vector>
#include <algorithm>


// CREER D'ABORD LES 3 DIFFERENTS TYPES DE VECTEURS QUI EXISTENT

// Procedure TriSelection(↔tab : tableau [TMAX] Entier
//                              , →nbElements : Entier)
// Variable
//   m : entier
//   i, j: entier
// Début
//   pour i de 0 à nbElements-1 faire
//     m ← i
//     pour j de i+1 à nbElements-1 faire
//       Si (tab[j] < tab[m] ) alors
//         m ← j
//       Finsi
//     FinPour
//     permute(tab[i], tab[m])
//   FinPour
// Fin


// int main(){
//     int m , i, j;
//     for(i=0; i< nbElements -1  )
// }



//fONCTION POUR FAIRE DES TRIES EN RANDOM???? 
// FONCTION QUI TRIE PAR ORDRE CROISSANT LA MOITIE DES VALEURS DU TAB 
void trie_croissant_moitie_du_tab(std::vector <int> &tab){
    
   
    for(size_t i=0; i < tab.size()/2; i++){  //Boucle pour parcourir la moitié du tableau et faire un trie croissant
        std::sort(tab.begin(), tab.begin() + tab.size()/2);
    }
}

// FONCTION QUI TRIE PAR ORDRE DECROISSANT LA MOITIE DES VALEURS DU TAB 
// ET L'AUTRE MOITIE EN RANDOM
void trie_decroissant_moitie_du_tab(std::vector<int> &tab){
    std::sort(tab.begin(), 
              tab.begin() + tab.size()/2, 
              [](int a, int b) { return a > b; });
}

int main(){
    std::vector <int> v={25,0,2,45,26,5,65,95,3,5};
    std::cout << "Valeur du tableau avant trie: " << std::endl ;
    for(int i:v)
        std::cout << i << std::endl;

    trie_croissant_moitie_du_tab(v);
    std::cout<<"Les valeurs du tableau apres trie croissant de la moitié des values du tableau: " << std::endl;
    for(size_t i=0 ; i < v.size(); i++)
        std::cout << v[i] <<std::endl; 
    trie_decroissant_moitie_du_tab(v);
    std::cout <<"Les valeurs du tableau apres trie decroissant: " << std::endl;
    for(size_t i=0; i < v.size(); i++)
        std::cout << v[i] << std::endl; 
    return 0;
}
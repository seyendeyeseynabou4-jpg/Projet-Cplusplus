#include <iostream>
#include "exo1.cpp"
#include <vector>

void affiche(const std::vector<int>  &v ) {
     for(.size_t i=0; i<v.size(); i++) {
         std::cout << v[i] << " " ;
     }
     std::cout << std::endl ;
}

int somme_entier( std::vector <int> &som)
{
    int somme=0 ;
    for (int c:som)
        {
            somme+=c;
        }
    return somme;
}

int main()
{   std::vector <int> tab={13,10,2,14} ;
    affiche(tab) ;
    somme_entier(tab);
    return 0 ;
}

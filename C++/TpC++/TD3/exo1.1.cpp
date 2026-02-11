#include <iostream>
#include <vector>
#include "exo1.1.hpp"

void affichage(const std::vector <int> &v)
{
    for(size_t i=0 ; i < v.size() ; i++)
    {
        std::cout << v[i];
        if (i != v.size() -1 )
            std::cout << ",";
        else 
            std::cout << std::endl;
    }
}

int somme_entier (const std::vector <int> &som)
{
    int somme=0;
    for (int c:som)
    {
        somme+=c;
    }
    return  somme;
}



int main()
{
   int somme;
   std::vector <int> tab={13,10,2,14};
   affichage(tab); 
   somme_entier(somme);
    return 0;
}
# include <iostream>
# include <vector> 

int somme_entier ( const std :: vector < int > &tab)
{
    int somme = 0;
    for (int i = 0 ; i < tab.size(); i++){
          somme+= tab[i];
    }
    std::cout << "la somme des entiers est : " << somme << std::endl;
    return somme;
}

int main()
{
    std::cout << somme_entier ({13,10,2,14}) << std::endl ;
    return 0 ;
}


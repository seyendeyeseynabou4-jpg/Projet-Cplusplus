#include <iostream> 
int main()
{
    //std::vector <double> tab ;
    size_t taille;
    std::cout << "Donnez une taille:";
    std::cin >> taille ;
    double * tab ;
    tab = new double [taille] ;   
    double somme=0 ;
    for (size_t i =0 ; i < taille ; i++)
    {
        std::cout << "Donnez la valeur num " << i + 1 << " du tableau : " ; 
        std::cin >> tab[i] ;
    }
    for (size_t i=0 ; i < taille ; i++)
        somme+= tab[i] ;
    double moyenne = somme/taille ; 
    std::cout << "La moyenne des valeurs du tableau sont: " << moyenne << std::endl; 
    delete [] tab ; 

    return 0 ; 

    

}




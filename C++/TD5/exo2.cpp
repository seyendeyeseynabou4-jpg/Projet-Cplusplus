/*argc donne le nombre d'argument qui ont été donnés sur la ligne de commande 
Ces arguments formeront le nombre de cases du tableau 
Chaque case est un pointeur sur une chaine C 

argv est un pointeur sur un tableau 
Chaque case de ce tableau est un pointeur sur un caractere 
Un caractere est la premiere lettre de chaque argument
*/
#include <iostream> 
#include <cstring>
int main( int argc , char * argv[])
{
    argv = new char [argc] ;
    for(int i = 0 ; i < argc ; i++)
        std::cout << argv[i] << std::endl ;  
    delete [] argv ; 
    return 0 ;
}




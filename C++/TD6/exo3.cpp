#include <iostream> 
#include <vector> 
#include <string> 
#include "exo3.hpp"

std::string ordre_inverser( std::vector <int> &v)
{
    std::string s="";
    for (int i=v.size()-1; i>=0; i--)
    {
        s+= std::to_string(v[i]) + " ";
    }
    return s;
}

std::vector <int> incrementer( std::vector <int> &tab){
    for( size_t i=0; i<tab.size(); i++){
        if(v[i]==9){
            v[i]=0;
        }
        else{
            v[i]=v[i]+1;
        }
    }
    for(size_t i=0, i < tab.size(); i++){
        if(tab[i] == '')
    }

}



int main()
{
    std::vector <int> v={13,25,7,3,9,15};
    ordre_inverser(v);
    std::cout << "Les valeurs dans l'ordre inverse sont : " << ordre_inverser(v) << std::endl;
    return 0;
}
#include <iostream> 
#include <vector>
#include <string>
#include"exo2.hpp"

    void delete_zero(std::vector <int> &v)
    {
        int compteur=0 ; 
        for(size_t i = 0 ; i < v.size() ; i++)
        {
            if(v[i]==0)
              compteur+=1 ; 
            else
                v[i-compteur]=v[i];
        }
        for(; compteur > 0 ; compteur--)
            v.pop_back();
    }

       std::vector <int> chaine(std::string &s , std::string &t )
       {
         int longueur ; 
         std::vector <int> v ; 
         if(s.size() < t.size())
            longueur= s.size(); 
        else
            longueur= t.size(); 
        for(int i=0 ; i < longueur ; i++)
        {
            if(t.size() == s.size())
                v.push_back(i);
        }
        return v;
       }


   void createList(List &S)
   {
        S.allocatedSize = 8 ;
        S.p = new int [8] ; 
        S.actualSize = 0;
   }

    void easyInsert(List &ajout)
    {
        size_t nombre ;
        ajout.p[actualSize] = nombre 
        ajout.actualSize ++ ; 
    }


       void doubleSize(List double)
       {
            size_t new_allocatedSize ;
            new_allocatedSize= double.allocatedSize *2 ; 
            int newtab[] *t = new int [new_allocatedSize]
            for(size_t i=0; i< new_allocatedSize ; i++)
                {
                    t[i] = p[i];
                }
            delete [] p ; 
            double.allocatedSize = new_allocatedSize ; 
       }



int main()
{
    std::vector <int> tab={ 13, 0, 0, 10, 2, 0, 14, 0 }; 
    delete_zero(tab); 
    for(size_t i=0 ; i< tab.size() ; i++)
    {
        std::cout << tab[i] << std::endl ; 
    }
    std::string s="abcd" ;
    std::string t="axc" ;
    std::vector <int> n= chaine(s,t) ;
    std::cout << "{"<< std::endl;
    for(size_t i=0 ; i < n.size(); i++)
    std::cout << n[i] << std::endl ;
    std::cout << "}" << std::endl ;
    return 0;
}
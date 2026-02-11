#ifndef EXO2_HPP
#define EXO2_HPP
#include <vector> 
 
   void delete_zero(std::vector <int> &v);

   std::vector <int> tab(std::string &s , std::string &t );

   struct List {
    size_t alllocatedSize ;
    size_t actualSize ;
    int tab[] *p ;
   };

   void createList(List &S);
   void easyInsert(List &ajout);
   void doubleSize(List double);

#endif
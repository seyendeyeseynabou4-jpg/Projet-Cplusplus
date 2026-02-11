#include <iostream>
#include <vector>




struct Point {
    double x , y ;
 };

int main () {
    std::vector < Point > v = {{2 ,3} ,{1 ,1} ,{2 ,4} ,{3 ,2}};

 // Ne marche pas , on ne sait pas comparer deux Point
 // std :: sort ( v . begin () , v . end ());

     for ( Point p : v )
        std::cout << "( " << p . x << ", " << p . y << ")" << std::endl ;

    return 0;
 }


                TRIE DES TABLEAUX 
                 Pour les types de base avec un ordre personnalise :

std::vector<int> v = {1, 5, 3, 9, 2};

// Tri decroissant au lieu de croissant
std::sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;  // Inverse l'ordre
});
// Resultat : {9, 5, 3, 2, 1}


            Pour des criteres complexes :

// Trier des strings par longueur au lieu de l'ordre alphabetique
std::sort(words.begin(), words.end(), [](const string &a, const string &b) {
    return a.length() < b.length();
});


dafni wone on passe par hawma lne j'ai compl'tement zapper frr 
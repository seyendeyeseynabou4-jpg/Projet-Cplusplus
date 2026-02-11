#include <iostream>
#include <vector>
#include <chrono>
#include "trie.hpp"



int main(){
        int n = 20;
    // int type ;
    
    // std::vector <int> tab = creattab(n, 1); 
    // std::cout << "Pour le type : " <<  << std::endl; 
    // std::chrono::steady_clock::time_point t_start = std::chrono::steady_clock::now();
    // std::vector <int> v = tab; 
    // trie_sort(v);
    // std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();

    // size_t duration = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
    // std::cout << "Le trie a duree " << duration << " microsecondes" << std::endl ; 

    // for (size_t i = 0; i + 1 < v.size(); i++)
    // if (v[i] > v[i+1])
    //     std::cerr << "ERREUR : tableau non trié !" << std::endl;




    int type = 3 ;
    for(int i = 1; i <= 3 ; i++){
        std::vector <int> tab = creattab(n, type);
        std::chrono::steady_clock::time_point t_start = std::chrono::steady_clock::now();
        std::vector <int> v = tab; 
        stableSort(v);
        size_t duration = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
        std::cout << "Le trie "<< type << " a duree " << duration << " microsecondes" << std::endl ; 

        for (size_t j = 0; j + 1 < v.size(); j++)
             if (v[i] > v[i+1])
                 std::cerr << "ERREUR : tableau non trié !" << std::endl;


                 
        std::chrono::steady_clock::time_point t_start = std::chrono::steady_clock::now();
        bubbleSort(v);
        size_t duration = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
        std::cout << "Le trie " << type << " a duree " << duration << " microsecondes" << std::endl ; 
        for (size_t j = 0; j + 1 < v.size(); j++)
            if (v[i] > v[i+1])
                std::cerr << "ERREUR : tableau non trié !" << std::endl;



        std::chrono::steady_clock::time_point t_start = std::chrono::steady_clock::now();
        sort_insertion (v);
        size_t duration = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
        std::cout << "Le trie "<< type << "a duree " << duration << " microsecondes" << std::endl ; 
        for (size_t j = 0; j + 1 < v.size(); j++)
            if (v[i] > v[i+1])
                std::cerr << "ERREUR : tableau non trié !" << std::endl;



        std::chrono::steady_clock::time_point t_start = std::chrono::steady_clock::now();
        quicksort_det_rec (v);
        size_t duration = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
        std::cout << "Le trie "<< type << "a duree " << duration << " microsecondes" << std::endl ; 
        for (size_t j = 0; j + 1 < v.size(); j++)
            if (v[i] > v[i+1])
                std::cerr << "ERREUR : tableau non trié !" << std::endl;




        std::chrono::steady_clock::time_point t_start = std::chrono::steady_clock::now();
        quicksort_rand_rec (v);
        size_t duration = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
        std::cout << "Le trie "<< type << " a duree " << duration << " microsecondes" << std::endl ; 
        for (size_t j = 0; j + 1 < v.size(); j++)
            if (v[i] > v[i+1])
                std::cerr << "ERREUR : tableau non trié !" << std::endl;



    }

    return 0;
}
#!/usr/bin/bash
echo "=== Compilation des fichiers communs ==="
g++ -std=c++17 -Wall -Ofast -c main.cpp
g++ -std=c++17 -Wall -Ofast -c creattab.cpp

echo "=== Compilation des algorithmes ==="

# Selection Sort
g++ -std=c++17 -Wall -Ofast -c trie_selection.cpp
g++ -std=c++17 -Wall -Ofast -c wrapper_selection.cpp
g++ -std=c++17 -Wall -Ofast -o selection main.o creattab.o trie_selection.o wrapper_selection.o

# Bubble Sort
g++ -std=c++17 -Wall -Ofast -c bubbleSort.cpp
g++ -std=c++17 -Wall -Ofast -c wrapper_bubble.cpp
g++ -std=c++17 -Wall -Ofast -o bubble main.o creattab.o bubbleSort.o wrapper_bubble.o

# Insertion Sort
g++ -std=c++17 -Wall -Ofast -c sortinsertion.cpp
g++ -std=c++17 -Wall -Ofast -c wrapper_insertion.cpp
g++ -std=c++17 -Wall -Ofast -o insertion main.o creattab.o sortinsertion.o wrapper_insertion.o

# Stable Sort
g++ -std=c++17 -Wall -Ofast -c stablesort.cpp
g++ -std=c++17 -Wall -Ofast -c wrapper_stable.cpp
g++ -std=c++17 -Wall -Ofast -o stable main.o creattab.o stablesort.o wrapper_stable.o

# Quicksort Déterministe
g++ -std=c++17 -Wall -Ofast -c quicksort_det.cpp
g++ -std=c++17 -Wall -Ofast -c wrapper_quickdet.cpp
g++ -std=c++17 -Wall -Ofast -o quickdet main.o creattab.o quicksort_det.o wrapper_quickdet.o

# Quicksort Aléatoire
g++ -std=c++17 -Wall -Ofast -c quicksort_rand.cpp
g++ -std=c++17 -Wall -Ofast -c wrapper_quickrand.cpp
g++ -std=c++17 -Wall -Ofast -o quickrand main.o creattab.o quicksort_rand.o wrapper_quickrand.o

echo "=== Exécution des tests ==="

for alg in selection bubble insertion stable quickdet quickrand
do
    echo "Algorithme: $alg"
    
    for t in 1 2 3
    do
        rm -f ${alg}_type${t}.data
        
        for i in $(seq 1 100)
        do
            n=$((i * 1000))
            echo "  Test: $alg n=$n type=$t"
            
            timeout 10m ./$alg $n $t >> ${alg}_type${t}.data
            ret=$?
            
            if [[ $ret -gt 120 ]]
            then
                echo "TIMEOUT OU CRASH: $alg type=$t n=$n"
                break
            fi
        done
    done
done

echo "=== Création des graphiques ==="
sage plot.sage

echo "=== Terminé ! ==="
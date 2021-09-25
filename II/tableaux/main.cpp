#include <iostream>
#include "tableaux.h"

int main(int argc, char const *argv[])
{
    int G = 0, D = 24;
    int taille = 25;
    long int * T1 = Array::generate(taille, CROISSANT);
    Array::show(T1, G, D);
    std::cout << (Array::isSorted(T1, G, D) ? "sorted" : "unsorted") << std::endl;
    delete[] T1;

    long int * T2 = Array::generate(taille, DECROISSANT);
    Array::show(T2, G, D);
    std::cout << (Array::isSorted(T2, G, D) ? "sorted" : "unsorted") << std::endl;
    delete[] T2;

    long int * T3 = Array::generate(taille, ALEATOIRE);
    Array::show(T3, G, D);
    std::cout << (Array::isSorted(T3, G, D) ? "sorted" : "unsorted") << std::endl;
    delete[] T3;

    return 0;
}

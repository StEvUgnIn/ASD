#include <iostream>
#include "tableaux.h"

int main(int argc, char const *argv[])
{
    int G = 0, D = 49;
    int taille = 50;

    std::shared_ptr<int64_t[]> T1 = Array::generate(taille, CROISSANT);
    Array::show(T1, G, D);
    std::cout << (Array::isSorted(T1, G, D) ? "sorted" : "unsorted") << std::endl;

    std::shared_ptr<int64_t[]> T2 = Array::generate(taille, DECROISSANT);
    Array::show(T2, G, D);
    std::cout << (Array::isSorted(T2, G, D) ? "sorted" : "unsorted") << std::endl;

    std::shared_ptr<int64_t[]> T3 = Array::generate(taille, ALEATOIRE);
    Array::show(T3, G, D);
    std::cout << (Array::isSorted(T3, G, D) ? "sorted" : "unsorted") << std::endl;

    return 0;
}

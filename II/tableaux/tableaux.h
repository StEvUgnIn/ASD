#pragma once

#define CROISSANT 0
#define DECROISSANT 1
#define ALEATOIRE -1

class Array {
public:
    static long int * generate(int taille, int mode);
    static void show(long int * T, int G, int D);
    static bool isSorted(long int * T, int G, int D);
};

void tri_insertion_iteratif(long int * T, int G, int D);
void tri_insertion_indice(long int * T, int G, int i);

#pragma once

#include <memory>

#define CROISSANT 0
#define DECROISSANT 1
#define ALEATOIRE -1

class Array 
{
public:
    static std::shared_ptr<int64_t[]> generate(int taille, int mode);
    static void show(std::shared_ptr<int64_t[]> T, int G, int D);
    static bool isSorted(std::shared_ptr<int64_t[]> T, int G, int D);
};

void tri_insertion_iteratif(std::shared_ptr<int64_t[]> T, int G, int D);
void tri_insertion_indice(std::shared_ptr<int64_t[]> T, int G, int i);

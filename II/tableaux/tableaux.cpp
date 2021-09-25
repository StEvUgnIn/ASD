#include <iomanip>
#include <iostream>
#include <vector>
#include "tableaux.h"

using namespace std;

long int *Array::generate(int taille, int mode)
{
    vector<long> *V(new vector<long>());
    switch (mode)
    {
    case CROISSANT:
    {
        for (int i = 0; i < taille; i++)
        {
            V->push_back(i);
        }
        break;
    }
    case DECROISSANT:
    {
        for (int i = taille - 1; i >= 0; i--)
        {
            V->push_back(i);
        }
        break;
    }
    case ALEATOIRE:
    {
        srand(time(nullptr));
        for (int i = 0; i < taille; i++)
        {
            V->push_back(rand() % 101); // entre 0 et 100
        }
        break;
    }
    }
    return V->data();
}

void Array::show(long int *T, int G, int D)
{
    cout << "[ ";
    for (int i = 0; i <= D; i++)
    {
        cout << setw(2) << T[i] << " ";
    }
    cout << "]";
    cout << endl;
}

bool Array::isSorted(long int *T, int G, int D)
{
    vector<long> source(T + G, T + D + 1);
    vector<long> sorted(source);
    tri_insertion_iteratif(sorted.data(), G, D);
    return source == sorted;
}

void tri_insertion_iteratif(long int *T, int G, int D)
{
    for (int i = G + 1; i <= D; i++)
    {
        tri_insertion_indice(T, G, i);
    }
}

void tri_insertion_indice(long int *T, int G, int i)
{
    long sauvegarde = T[i];
    int j = i - 1;
    while (j >= G && T[j] > sauvegarde)
    {
        T[j + 1] = T[j]; // copie d'une case dans la suivante
        j = j - 1;
    }
    T[j + 1] = sauvegarde;
}

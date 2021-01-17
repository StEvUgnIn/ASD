#include "fonctions.h"
#include <stdbool.h>
#include <stdio.h>

/**
 * echange deux valeurs d'un tableau
 */
void echanger(int *tab, int i, int j)
{
    tab[i] ^= tab[j] ^= tab[i] ^= tab[j];
}

/**
 * algorithme de tri
 */
void parcourir(int *tab, int h, int b)
{
    for(int* ptr = tab+b+1; ptr >= tab+h; --ptr)
    {
        if (ptr[1] < ptr[0]) echanger(ptr, 1, 0);    
    }
}

/**
 * affiche un tableau de i à j
 */
void afficher(int *tab, int i, int j)
{
    for(; i <= j; ++i) printf("%d ", tab[i]);
    printf("\n");
}

/**
 * algorithme de tri simple
 */
void tri_bulle(int t[], int haut, int bas)
{
    for(int j = 1; j < bas - haut; ++j)
    {
        for(int i = bas; i > haut + j; --i)
        {
            if (t[i] < t[i-1])
                echanger(t, i, i-1);
        }
    }
}

/**
 * drapeau sert de flag lors du tri pour assurer un nombre minimale de comparaison
 */
void tri_bulle_drapeau(int t[], int haut, int bas)
{
    bool drapeau = false;
    int j;
    do {
        j = 1;
        for(int i = bas; i > haut + j; --i)
        {
            if (t[i] < t[i-1]) {
                echanger(t, i, i-1);
                drapeau = true;
            }
        }
        ++j;
    } while (j > bas - haut || !drapeau);
}

/**
 * tri par extraction en plaçant le min a gauche
 */
void tri_extraction(int *t, int g, int d)
{
    for(int i = 0; i < d; ++i)
    {
        placer_min_g(t, g+i, d);
    }
}

/**
 * place min a gauche
 */
void placer_min_g(int *t, int g, int d)
{
    int min = g;
    for(int i = g+1; i <= d; ++i)
    {
        min = t[min] < t[i] ? min : i;
    }
    if (min != g) echanger(t, min, g);
}
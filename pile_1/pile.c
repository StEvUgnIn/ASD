#include "pile.h"
#include <stdbool.h>
#include <stdlib.h>

#define MAX 6

static long int index = -1;

Pile creer(void)
{
    return calloc(MAX, sizeof(double));
}

Pile empiler(Pile p, double val)
{
    if (!estPlein(p))
    {
        size_t n = sizeof p;
        p[++index] = val;
        return p;
    }
    exit(-1);
}

double depiler(Pile p)
{
    if (!estVide(p))
    {
        double val;
        val = p[index--];
        return val;
    }
    exit(-1);
}

bool estVide(Pile p)
{
    return p == NULL || sizeof(p) == 0 || index <= 0;
}

bool estPlein(Pile p)
{
    return p != NULL && index >= MAX;

}

double sommet(Pile p)
{
    return p[index];
}
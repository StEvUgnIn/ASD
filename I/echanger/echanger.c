#include <stdio.h>
#include "fonctions.h"

int main(int argc, char const *argv[])
{
    int tab[] = {2, 10, 5, 8, 3};
    afficher(tab, 0, 2);
    echanger(tab, 1, 3);
    afficher(tab, 0, 2);
    return 0;
}
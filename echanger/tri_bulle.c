#include <stdio.h>
#include "fonctions.h"

int main(int argc, char const *argv[])
{
    int tab[] = { 7, 5, 8, 3, 2 };
    parcourir(tab, 0, 4);
    afficher(tab, 0, 4);
    return 0;
}

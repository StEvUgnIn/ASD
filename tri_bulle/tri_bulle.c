#include <stdio.h>
#include "../echanger/fonctions.h"

int main(void)
{
    int tab[] = {0, 25, 18, 4, 3, 2, 1};
    afficher(tab, 0, 6);
    //tri_bulle(tab, 0, 6);
    tri_bulle_drapeau(tab, 0, 6);
    afficher(tab, 0, 6);
    return 0;
}

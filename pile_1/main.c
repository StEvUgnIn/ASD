#include <stdlib.h>
#include <stdio.h>
#include "pile.h"

int main(void)
{
    Pile p = creer();
    empiler(p, 1.2);
    empiler(p, 7.7);
    printf("%lf\n", depiler(p));
    printf("%lf\n", sommet(p));
    free(p); // pas indispensable ici
    return 0;
}

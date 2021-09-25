#include "../echanger/fonctions.h"

int main(void)
{
    int tab[] = {1, 12, 53, 15, 33, 46, 10, 8};
    afficher(tab, 0, 7);
    tri_extraction(tab, 0, 7);
    afficher(tab, 0, 7);
    return 0;
}

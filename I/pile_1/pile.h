#include <stdbool.h>

typedef double* Pile;

Pile creer(void);
Pile empiler(Pile, double);
double depiler(Pile);
bool estVide(Pile);
bool estPlein(Pile);
double sommet(Pile);

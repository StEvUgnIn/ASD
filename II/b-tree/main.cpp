#include "main.hpp"

using namespace std;

int main()
{
  int N = 10;
  shared_ptr<TNoeud> arbre = ConstruitArbre(N);
  afficher_arbre(arbre, hauteur(N));
  return 0;
}

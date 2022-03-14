#include <iostream>
#include <cmath>
#include "tnoeud.h"

using namespace std;

Tree ConstruitArbre(int64_t N)
{
  Tree r = nullptr;
  if (N > 0)
  {
    Tree p = r = make_shared<TNoeud>();
    Tree q = r;
    for (int64_t i = 0; i < N; i++)
    {
      if (q == p)
      {
        if (p == nullptr)
        {
          p = make_shared<TNoeud>();
        }
        p = q->gauche; /* ptr->gauche */
      }
      else if (q->gauche == p)
      {
        p = make_shared<TNoeud>();
        p = q->droite; /* ptr->..->droite */
      }
      else if (q->droite == p)
      {
        p = make_shared<TNoeud>();
        p = q->gauche; /* ptr->..->gauche */
      }
    }
  }
  return r;
}

void afficher_arbre(Tree noeud, int64_t H)
{
  if (noeud != nullptr)
  {
    for (int64_t i = 0; i < pow(2, H) && noeud != nullptr; i++)
    {
      racine(noeud, pow(2, H) - i);
      noeud = noeud->droite;
    }
  }
}

int hauteur(int N)
{
  return log2(N);
}

void racine(Tree arbre, int64_t H)
{
  for (int64_t i = 0; i < H; i++)
  {
    if (arbre != nullptr)
    {
      cout << arbre->donnee << endl;
      if (arbre->droite != nullptr)
      {
        cout << arbre->droite->donnee << endl;
      }
      if (arbre->gauche != nullptr)
      {
        arbre = arbre->gauche;
      }
    }
  }
}

void ParcoursIter(Tree noeud)
{
  
}

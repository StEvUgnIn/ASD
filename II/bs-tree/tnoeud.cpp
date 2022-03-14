#include "tnoeud.hpp"

bool Chercher(long x, Tree const& B)
{
  if (B == nullptr)
  {
    return false;
  }
  
  if (x == B->donnee)
  {
    return true;
  }

  if (x <= B->donnee)
  {
    return Chercher(x, B->gauche);
  }
  
  return Chercher(x, B->droite);
}

Tree AjouterFeuille(long x, Tree const& A)
{
  if (A == nullptr)
  {
    return Tree();
  }
  
  Tree tree = Tree();

  if (x <= A->donnee)
  {
    tree->donnee = x;
    tree->droite = A->droite;
    tree->gauche = AjouterFeuille(x, nullptr);
  }
  else
  {
    tree->donnee = x;
    tree->droite = AjouterFeuille(x, nullptr);
    tree->gauche = A->gauche;
  }
  return tree;
}

void SupMax(long& Max, Tree const& A)
{
  // ! Chercher Max
  // ! Mem Max
  // ! Mise à jour A
  // ! delete
}

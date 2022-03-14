#pragma once
#include <memory>

struct TNoeud
{
  int donnee;
  Tree gauche;
  Tree droite;
};

#ifndef __cplusplus
typedef struct TNoeud TNoeud;
#endif

typedef
#ifdef __cplusplus
std::shared_ptr<TNoeud>
#else
TNoeud*
#endif
Tree;

Tree ConstruitArbre(int64_t N);

void afficher_arbre(Tree noeud, int64_t H);

void racine(Tree arbre, int64_t H);

void ParcoursIter(Tree noeud);

int hauteur(int N);

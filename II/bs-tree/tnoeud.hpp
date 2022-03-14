#pragma once
#include "../b-tree/tnoeud.h"

bool Chercher(long x, Tree const& A);

Tree AjouterFeuille(long x, Tree const& A);

void SupMax(long& Max, Tree const& A);

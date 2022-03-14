#include <chrono>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <memory>
#include <random>
#include "tableaux.h"

using namespace std;

shared_ptr<int64_t[]> Array::generate(int taille, int mode)
{
  shared_ptr<int64_t[]> T = make_unique<int64_t[]>(taille);
  switch (mode)
  {
  case CROISSANT:
  {
    for (int i = 0; i < taille; i++)
    {
      T.get()[i] = i;
    }
    break;
  }
  case DECROISSANT:
  {
    for (int i = taille - 1; i >= 0; i--)
    {
      T.get()[taille - i - 1] = i;
    }
    break;
  }
  case ALEATOIRE:
  {
    auto seed = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine random_engine(seed);
    for (int i = 0; i < taille; i++)
    {
      T.get()[i] = random_engine() % 101L;
    }
    break;
  }
  }
  return T;
}

void Array::show(shared_ptr<int64_t[]> T, int G, int D)
{
  cout << "[ ";
#ifdef STL_COPY
  copy(T.get() + G, T.get() + D + 1, ostream_iterator<int64_t>(cout, " "));
#else
  for (int i = 0; i <= D; i++)
  {
    cout << setw(2) << T.get()[i] << " ";
  }
#endif
  cout << "]";
  cout << endl;
}

bool Array::isSorted(shared_ptr<int64_t[]> T, int G, int D)
{
  int taille = D - G + 1;
  shared_ptr<int64_t[]> S = make_unique<int64_t[]>(taille);
  copy(T.get() + G, T.get() + D + 1, S.get() + G);
  tri_insertion_iteratif(S, G, D);
  return equal(T.get() + G, T.get() + D + 1, S.get() + G);
}

void tri_insertion_iteratif(shared_ptr<int64_t[]> T, int G, int D)
{
  for (int i = G + 1; i <= D; i++)
  {
    tri_insertion_indice(T, G, i);
  }
}

void tri_insertion_indice(shared_ptr<int64_t[]> T, int G, int i)
{
  int64_t sauvegarde = T.get()[i];
  int j = i - 1;
  while (j >= G && T.get()[j] > sauvegarde)
  {
    T.get()[j + 1] = T.get()[j]; // copie d'une case dans la suivante
    j = j - 1;
  }
  T.get()[j + 1] = sauvegarde;
}

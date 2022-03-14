#include "minheap.h"

MinHeap::MinHeap() : MinHeap(nullptr, 0)
{
}

MinHeap::MinHeap(long* S, size_t N) : S(S), N(N)
{
}

MinHeap::~MinHeap()
{
}

void MinHeap::Creer(long* S)
{
  this->S = S;
}

long MinHeap::Minimum()
{
  return S[0];
}

long MinHeap::ExtraireMin()
{
  long min = S[0];
  std::move(this->S + 1, this->S + N, this->S);
  N--;
  return min;
}

long MinHeap::DiminuerClef(size_t x, long k)
{
  return this->S[x] -= k;
}

bool MinHeap::EstVide()
{
  return N == 0;
}

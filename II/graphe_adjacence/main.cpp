#include "graphe.hpp"

using namespace std;

int main()
{
  auto graphe = make_shared<Graphe>('A', 1);
  graphe->CreerGraphe(10);
  graphe->AfficherGraphe();
  graphe.reset();
  return 0;
}

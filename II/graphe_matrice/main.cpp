#include "graphe.hpp"

using namespace std;

int main()
{
  auto graphe = Graphe('A', 1);
  graphe.CreerGraphe(10);
  graphe.AjouterArc('A', 'B');
  graphe.AjouterArc('A', 'F');
  graphe.AjouterArc('A', 'G');
  graphe.AjouterArc('A', 'C');
  graphe.AjouterArc('E', 'G');
  graphe.AjouterArc('D', 'F');
  graphe.AjouterArc('E', 'F');
  graphe.AjouterArc('D', 'E');
  graphe.AjouterArc('I', 'J');
  graphe.AjouterArc('I', 'K');
  graphe.AjouterArc('J', 'K');
  graphe.AfficherGraphe();
  return 0;
}

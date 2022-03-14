#pragma once
#include <functional>
#include <memory>
#include <ostream>

class Graphe
{
public:
  /**
   * Constructeur par défaut
   */
  Graphe();
  
  /**
   * Constructeur idéal
   */
  Graphe(char s, int p = -1);
  
  /**
   * Destructeur
   */
  ~Graphe();

  /**
   * alloue la mémoire pour une matrice capable de représenter un graphe avec nb
   * sommets. Initialise cette matrice avec des valeurs nulles (sommets non reliés)
   */
  void CreerGraphe(long nb);

  /**
   * Affichera dans la console la matrice sous une forme lisible
   */
  void AfficherGraphe();

  /**
   * ajoutera un arc pondéré s1 <---> s2 dans la représentation matricielle
   */
  void AjouterArc(char s1, char s2, int p = 1, bool oriente = false);

  /**
   * ajoutera un arc s1 --> s2 dans la représentation matricielle
   */
  void AjouterArcOriente(char s1, char s2, int p = 1);

  /**
   * renvoie le degré du sommet (nombre d'arcs l'atteignant)
   */
  int Degre(char sommet);

  /**
   * libère la mémoire
   */
  void SupprimerGraphe();

  /**
   * renvoie vrai si le graphe est fortement connexe, faux sinon
   *
   * Un graphe est dit fortement connexe (dense) s'il
   * comporte beaucoup d'arcs et faiblement connexe (sparse) s'il comporte peu d'arcs.
   */
  bool EstFortementConnexe();

  /**
   * renvoie vrai si le graphe est orienté, faux sinon
   *
   * Les graphes orientés (directed) dans lesquels chaque arc possède un sens.
   */
  bool EstOriente();

  /**
   * renvoie vrai si le graphe est pondéré, faux sinon
   *
   * Les graphes pondérés (weighted) pour lesquels les arcs
   * comportent un ou plusieurs attributs; ces derniers
   * seront alors toujours positifs.
   */
  bool EstPondere();

  /**
   * renvoie vrai si le graphe est connexe, faux sinon
   *
   * Un graphe est connexe (connected) s'il existe un chemin
   * entre toute paire de sommets, ce qui n'est
   * clairement pas le cas de l'exemple fil conducteur.
   */
  bool EstConnexe();

  void ParcoursProfondeurRecursif();

  // opérateurs
  std::ostream &operator<<(std::ostream &stream);

  friend std::ostream &operator<<(std::ostream &stream, const Graphe &graphe);

  bool operator==(const Graphe &graphe);

  // static
  static bool Connexion(Graphe &graphe);

  // getters
  char Sommet();

  int Ponderation();

  Graphe *GetGraphe();

  bool GetVisite();

private:
  bool VSPR(std::function<bool(Graphe &)> traiter);

  // attributs
  char s;
  int p;
  bool visite;
  long nb;
  std::shared_ptr<Graphe[]> graphe; // liste d'adjacence
};

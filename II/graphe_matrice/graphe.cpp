#include <cassert>
#include <iostream>
#include <iterator>
#include "graphe.hpp"

using namespace std;

Graphe::Graphe() : Graphe(0x0) {}

Graphe::Graphe(char s, int p)
{
  this->s = s;
  this->p = p;
}

Graphe::~Graphe()
{
  this->SupprimerGraphe();
}

void Graphe::CreerGraphe(long nb)
{
  this->SupprimerGraphe();

  this->graphe.reserve(nb);

  /*for (long i = 0; i < nb; i++)
  {
    this->graphe.push_back(adjacence_t());
    this->visites.push_back(vector<bool>());

    this->graphe.back().reserve(nb);
    this->visites.back().reserve(nb);

    for (long j = 0; j < nb; j++)
    {
      this->graphe.back().push_back(Graphe());
      this->visites.back().push_back(false);
    }
  }*/
  this->nb = nb;
}

void Graphe::AfficherGraphe()
{
  cout << *this << endl;
}

ostream &Graphe::operator<<(ostream &stream)
{
  stream << this->s << " (" << this->p << ")" << endl;

  for (adjacence_t &v : this->graphe)
  {
    stream << "[ ";
    for (Graphe &g : v)
    {
      stream << g.s << " (" << g.p << ")" << " ";
    }
    stream << "]" << endl;
  }
  return stream;
}

ostream &operator<<(ostream &stream, const Graphe &graphe)
{
  stream << graphe.s << " (" << graphe.p << ")" << endl;

  for (Graphe::adjacence_t v : graphe.graphe)
  {
    stream << "[ ";
    for (Graphe &g : v)
    {
      stream << g.s << " (" << g.p << ")" << " ";
    }
    stream << "]" << endl;
  }
  return stream;
}

void Graphe::AjouterArc(char s1, char s2, int p, bool oriente)
{
  assert(s1 != s2);
  if (s1 == this->s)
  {
    graphe.push_back(vector<Graphe>());
    if (oriente)
    {
      graphe.back().push_back(Graphe(s2, p));
    }
    else
    {
      graphe.back().push_back(Graphe(s2));
    }
    return;
  }
  if (s2 == this->s)
  {
    graphe.push_back(vector<Graphe>());
    if (oriente)
    {
      graphe.back().push_back(Graphe(s1, p));
    }
    else
    {
      graphe.back().push_back(Graphe(s1));
    }
    return;
  }
  for (vector<Graphe> v1 : this->graphe)
  {
    for (Graphe &g1 : v1)
    {
      if (g1.s == s1)
      {
        for (vector<Graphe> v2 : this->graphe)
        {
          if (oriente)
          {
            v2.push_back(Graphe(s2, p));
          }
          else
          {
            v2.push_back(Graphe(s2));
          }
        }
        if (g1.s == s2)
        {
          for (vector<Graphe> v2 : this->graphe)
          {
            for (Graphe &g2 : v2)
            {
              if (g2.s == 0)
              {
                if (oriente)
                {
                  v2.push_back(Graphe(s1, p));
                }
                else
                {
                  v2.push_back(Graphe(s2));
                }
              }
            }
          }
        }
      }
    }
  }
}

void Graphe::AjouterArcOriente(char s1, char s2, int p)
{
  this->AjouterArc(s1, s2, p, true);
}

int Graphe::Degre(char sommet)
{
  int degre = (this->s == sommet);
  for (adjacence_t v : graphe)
  {
    for (Graphe &g : v)
    {
      if (sommet == g.s)
      {
        degre++;
      }
    }
  }
  return degre;
}

void Graphe::SupprimerGraphe()
{
}

bool Graphe::EstFortementConnexe()
{
  bool fortementConnexe = true;
  for (adjacence_t v : this->graphe)
  {
    for (Graphe &g : v)
    {
      fortementConnexe &= g.EstConnexe();
    }
  }
  return fortementConnexe;
}

bool Graphe::EstOriente()
{
  for (adjacence_t v : this->graphe)
  {
    for (Graphe &g : v)
    {
      if (*this == g)
      {
        return true;
      }
    }
  }
  return false;
}

bool Graphe::operator==(const Graphe &graphe)
{
  return this->p == graphe.p &&
         this->s == graphe.s;
}

bool Graphe::EstPondere()
{
  if (this->p > -1)
  {
    return true;
  }
  for (adjacence_t v : this->graphe)
  {
    for (Graphe &g : v)
    {
      if (g.p > -1)
      {
        return true;
      }
    }
  }
  return false;
}

bool Graphe::EstConnexe()
{
  bool connexe = false;

  if (graphe.size() > 0)
  {
    connexe = true;
  }
  for (adjacence_t v : this->graphe)
  {
    for (Graphe &g : v)
    {
      connexe |= g.VSPR(Graphe::Connexion);
    }
  }
  return connexe;
}

bool Graphe::Connexion(Graphe &graphe)
{
  return graphe.Degre(graphe.Sommet()) > 0;
}

void Graphe::ParcoursProfondeurRecursif()
{
  init_visites();

  this->VSPR(nullptr);
}

void Graphe::init_visites()
{
  for (long i = 0; i < visites.size(); i++)
  {
    for (long j = 0; j < visites[i].size(); j++)
    {
      visites[i][j] = false;
    }
  }
}

bool Graphe::VSPR(function<bool(Graphe &)> traiter)
{
  init_visites();

  bool r = false;
  r &= traiter(*this);
  for (long i = 0; i < graphe.size(); i++)
  {
    for (long j = 0; j < graphe[i].size(); j++)
    {
      r &= graphe[i][j].VSPR(traiter);
      visites[i][j] = true;
    }
  }
  return r;
}

char Graphe::Sommet()
{
  return s;
}

int Graphe::Ponderation()
{
  return p;
}

Graphe::graphe_t Graphe::GetGraphe()
{
  return this->graphe;
}

#include <cassert>
#include <iostream>
#include "graphe.hpp"

using namespace std;

Graphe::Graphe() : Graphe(0x0) {}

Graphe::Graphe(char s, int p)
{
  this->s = s;
  this->p = p;
  this->visite = false;
}

Graphe::~Graphe()
{
  this->SupprimerGraphe();
}

ostream &Graphe::operator<<(ostream &stream)
{
  stream << *this << endl;

  for (long i = 0; i < this->nb; i++)
  {
    Graphe &g1 = this->graphe[i];
    stream << g1 << "[ ";

    for (long j = 0; i < g1.nb; j++)
    {
      Graphe &g2 = g1.graphe[j];
      stream << g2 << " ";
    }
    stream << "]" << endl;
  }
  return stream;
}

ostream &operator<<(ostream &stream, const Graphe &graphe)
{
  if (graphe.s == 0x0 && graphe.p == -1)
  {
    return stream;
  }
  return stream << graphe.s << " (" << graphe.p << ")";
}

void Graphe::CreerGraphe(long nb)
{
  this->SupprimerGraphe();
  this->graphe = shared_ptr<Graphe[]>(new Graphe[nb]);
  for (long i = 0; i < nb; i++)
  {
    this->graphe[i].s = this->s + i + 1;
  }
  this->nb = nb;
}

void Graphe::AfficherGraphe()
{
  cout << *this << endl;
}

void Graphe::AjouterArc(char s1, char s2, int p, bool oriente)
{
  assert(s1 != s2);
  for (long i = 0; i < this->nb; i++)
  {
    Graphe &g1 = this->graphe[i];

    if (g1.s == s1)
    {
      for (long j = 0; j < g1.nb; j++)
      {
        Graphe &g2 = g1.graphe[j];

        if (g2.s == 0)
        {
          g2.s = s2;
          g2.p = p;
          if (oriente)
          {
            g2.graphe[0] = g1;
          }
        }
      }
    }
    if (g1.s == s2)
    {
      for (long j = 0; j < g1.nb; j++)
      {
        Graphe &g2 = g1.graphe[j];

        if (g2.s == 0)
        {
          g2.s = s1;
          g2.p = p;
          if (oriente)
          {
            g2.graphe[0] = g1;
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
  int degre = 0;
  for (long i = 0; i < this->nb; i++)
  {
    Graphe &g1 = this->graphe[i];

    for (long j = 0; j < g1.nb; j++)
    {
      Graphe &g2 = g1.graphe[j];

      if (sommet == g2.s)
      {
        degre++;
      }
    }
  }
  return degre;
}

void Graphe::SupprimerGraphe()
{
  this->graphe.reset();
}

bool Graphe::EstFortementConnexe()
{
  bool fortementConnexe = true;
  for (long i = 0; i < this->nb; i++)
  {
    fortementConnexe &= this->graphe[i].EstConnexe();
    for (long j = 0; j < this->graphe[i].nb; j++)
    {
      fortementConnexe &= this->graphe[i].graphe[j].EstConnexe();
    }
  }
  return fortementConnexe;
}

bool Graphe::EstOriente()
{
  for (long i = 0; i < nb; i++)
  {
    if (*this == graphe[i])
    {
      return true;
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
  for (long i = 0; i < this->nb; i++)
  {
    if (this->graphe[i].p > -1)
    {
      return true;
    }
  }
  return false;
}

bool Graphe::EstConnexe()
{
  bool connexe = false;

  if (nb > 0)
  {
    connexe = true;
  }
  for (long i = 0; i < nb; i++)
  {
    connexe |= this->graphe[i].VSPR(Graphe::Connexion);
  }
  return connexe;
}

bool Graphe::Connexion(Graphe &graphe)
{
  return graphe.Degre(graphe.Sommet()) > 0;
}

void Graphe::ParcoursProfondeurRecursif()
{
  this->visite = false;

  for (long i = 0; i < nb; i++)
  {
    this->graphe[i].visite = false;
    for (long j = 0; j < graphe[i].nb; j++)
    {
      this->graphe[i].graphe[j].visite = false;
    }
  }

  this->VSPR(nullptr);
  for (long i = 0; i < nb; i++)
  {
    this->graphe[i].VSPR(nullptr);
  }
}

bool Graphe::VSPR(function<bool(Graphe &)> traiter)
{
  bool r = false;
  if (!this->visite)
  {
    this->visite = true;
    if (traiter != nullptr)
    {
      r &= traiter(*this);
    }
    for (long i = 0; i < this->nb; i++)
    {
      r &= this->graphe[i].VSPR(traiter);
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

Graphe *Graphe::GetGraphe()
{
  return this->graphe.get();
}

bool Graphe::GetVisite()
{
  return this->visite;
}

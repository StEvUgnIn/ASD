#include "pile.hh"

Pile::Pile()
{
    front = pile = new double [10];
}

Pile::~Pile()
{
    delete[] front; // pile is implicitely deleted
}

Pile& Pile::empiler(double value)
{
    if (pile != front+10)
    {
        *(pile++) = value;
        return *this;
    }
    exit(-1);
}

double Pile::depiler()
{
    if (pile != front)
    {
        return *(--pile);
    }
    exit(-1);
}

bool Pile::estPlein()
{
    return !estVide();
}

bool Pile::estVide()
{
    return pile == nullptr || sizeof(pile) == 0 && pile - front == 0;
}

double Pile::sommet()
{
    return *front;
}
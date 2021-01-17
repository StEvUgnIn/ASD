#include "pile.hh"

Pile::Pile()
{
    front = pile = new Node();
}

Pile::~Pile()
{
    delete[] front; // pile is implicitely deleted
}

Pile& Pile::empiler(double value)
{
    if (pile != front+10)
    {
        if (pile->next == nullptr) pile->next = new Node();
        pile->value = value;
        pile->next->prev = pile;
        pile = pile->next;
        return *this;
    }
    exit(-1);
}

double Pile::depiler()
{
    if (pile != front)
    {
        pile = pile->prev;
        return pile->value;
    }
    exit(-1);
}

bool Pile::estPlein()
{
    return !estVide();
}

bool Pile::estVide()
{
    return pile == nullptr || sizeof(pile) == 0 && pile->prev == nullptr;
}

double Pile::sommet()
{
    return front->value;
}
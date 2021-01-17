#include <iostream>
#include "pile.hh"

using namespace std;

int main()
{
    auto p = make_shared<Pile>();
    //Pile *p = new Pile();
    p->empiler(1.2);
    p->empiler(7.7);
    cout << p->depiler() << endl; 
    cout << p->sommet() << endl;
    //delete p; // pas dans C++17
    return 0;
}

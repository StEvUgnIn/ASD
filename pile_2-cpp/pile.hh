#include <vector>
#include <memory>

struct Node {
    Node *next = nullptr;
    Node *prev = nullptr;
    double value;
};

class Pile
{
    Node* pile;
    Node* front;
public:
    Pile();
    ~Pile();
    Pile& empiler(double);
    double depiler();
    bool estVide();
    bool estPlein();
    double sommet();
};

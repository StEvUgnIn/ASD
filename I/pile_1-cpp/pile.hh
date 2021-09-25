#include <vector>
#include <memory>

class Pile
{
    double* pile;
    double* front;
public:
    Pile();
    ~Pile();
    Pile& empiler(double);
    double depiler();
    bool estVide();
    bool estPlein();
    double sommet();
};

#include <iostream>
#include <iomanip>
#include "quicksort.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "allocation()" << endl;
    shared_ptr<int64_t[]> tab(new int64_t[11]{26, 28, 5, 25, 20, 35, 60, 75, 12, 42, 23});
    cout << "affichage()" << endl;
    cout << "[ ";
    for (int i = 0; i < 11; ++i)
    {
        cout << setw(2) << tab[i] << " ";
    }
    cout << "]" << endl;
    cout << "explorer()" << endl;
    int pivot = explorer(tab, 0, 10);
    cout << "[ ";
    for (int i = 0; i < 11; ++i)
    {
        cout << tab[i] << " ";
    }
    cout << "]";
    cout << endl;
    cout << "pivot: " << pivot;
    cout << endl;
    return 0;
}

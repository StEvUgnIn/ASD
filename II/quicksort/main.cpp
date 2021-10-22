#include <iostream>
#include <iomanip>
#include "quicksort.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "allocation()" << endl;
    int64_t values[] = {26, 28, 5, 25, 20, 35, 60, 75, 12, 42, 23};
    shared_ptr<int64_t[]> tab = make_shared<int64_t[]>(11);
    cout << "copie()" << endl;
    cout << "[ ";
    for (int i = 0; i < 11; ++i)
    {
        tab[i] = values[i];
        cout << setw(2) << values[i] << " ";
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

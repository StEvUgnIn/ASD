#include <iostream>
#include <iomanip>
#include <memory>
#include "merge.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int i = 0, m = 10, n = 20;
    cout << "Tri fusion" << endl;
    int64_t list[] = { 34, 35, 37, 38, 39, 40, 48, 49, 51, 58, 42, 44, 48, 49, 50, 52, 53, 55, 56, 59 };
    int64_t *sorted = new int64_t[n];
    merge(list, sorted, i, m, n);
    cout << "T  ";
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setw(2) << list[i] << " ";
    }
    cout << "]";
    cout << endl << "S  ";
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setw(2) << sorted[i] << " ";
    }
    cout << "]";
    cout << endl;
    delete[] sorted;
    #ifdef WAIT
    cin.get();
    #endif
    return 0;
}

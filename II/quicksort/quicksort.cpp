#include "quicksort.h"

using namespace std;

int explorer(shared_ptr<int64_t[]> T, int G, int D)
{
    int i = G, j = D, k = G + 1;

    while (i < j)
    {
        while (k < D)
        {
            if (T[k] > T[G])
            {
                i = G + k;
            }
            k++;
        }
        while (k > G)
        {
            if (T[k] <= T[D])
            {
                j = D - k;
            }
            k--;
        }
        if (i < j)
        {
            echanger(T, i, j);
        }
    }
    echanger(T, G, j);
    return j;
}

void echanger(shared_ptr<int64_t[]> T, int i, int j)
{
    T[i] ^= T[j] ^= T[i] ^= T[j];
}

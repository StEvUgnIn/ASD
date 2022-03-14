#include <cassert>
#include <cstring>
#include "merge.h"

void merge(int64_t *list, int64_t *sorted, int i, int m, int n)
{
    assert(m <= n && i <= n);
    assert(list != nullptr && sorted != nullptr);

    for (int j = 0, k = 0; i <= m && m + i + 1 <= n - 1; i++)
    {
        if (list[j] <= list[m + i + 1])
        {
            sorted[k] = list[j];
            j = i + 1;
        }
        if (list[m + i + 1] < list[j])
        {
            sorted[k] = list[m + i + 1];
        }
        k++;
        if (j < m)
        {
            memcpy(sorted + k, list + j, (m - j) * sizeof(sorted));
            i = j = m;
            k += m - j;
        }
        if (m + i < n)
        {
            memcpy(sorted + k, list + m + i + 1, (n - m + i - 1) * sizeof(sorted));
            k += n - m + i - 1;
        }
    }
}

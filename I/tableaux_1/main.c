/* 
 * File:   main.c
 * Author: steve.huguenin
 *
 * Created on 20. février 2019, 08:57
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct min_max {
    int max; 
    int min;
} MinMax;

struct min_max tab_min_max (int length, int tableau[length]);

int tab_find(int length, int *p_tab, int value);

/*
 *
 */
#define length 5
int main(void) {
    int TAB[length] = { 7, 3, 42, 1, 8 };
    
    MinMax minMax = tab_min_max(length, TAB);
    
    printf ("(min, max) = (%i, %i)\n", minMax.min, minMax.max);
    printf ("index = %i\n", tab_find(length, TAB, TAB[2]));
    printf ("index = %i\n", tab_find(length, TAB, 26));
    return (EXIT_SUCCESS);
}
#undef length

static int* addr_find(int n, int * p_tab, int value)
{
    if (p_tab != NULL && n > 0)
    {
        if (*p_tab != value)
            return addr_find(n-1, p_tab+1, value);
        return p_tab;
    }
    return NULL;
}

int tab_find(int length, int * p_tab, int value) 
{
    int *ptr = addr_find(length, p_tab, value);
#ifdef DEBUG
    printf ("\n%p\n", ptr);
#endif
    if (ptr != NULL) return (int)(ptr - p_tab);
    return -1;
}

struct min_max tab_min_max (int length, int tableau[length]) 
{
    if (tableau != NULL & length > 0)
    {
        MinMax result = { 0, 0 };
        for (int i = 1; i < length; ++i)
        {
            if (tableau[result.min] > tableau[i]) result.min = i;
            if (tableau[result.max] < tableau[i]) result.max = i;
        }

        return result;
    }
    MinMax result = { -1, -1 };
    return result;
}


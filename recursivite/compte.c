#include <stdio.h>

void compte (int n);
void decompte (int n);

int main(int argc, char const *argv[])
{
    compte (50);
    decompte (50);
    return 0;
}

void compte (int n)
{
    printf("%d ", n);
    if (n > 0)
        return compte (n - 1);
    printf("\n");
}

void decompte (int n)
{
    if (n > 0)
        decompte (n - 1);
    printf("%d ", n);
}

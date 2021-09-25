#include <stdio.h>

int factorielle (int n);

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    printf("%d", factorielle(num));
    return 0;
}

int factorielle (int n)
{
    if (n != 0)
        return n * factorielle (n - 1);
    return 1;
}

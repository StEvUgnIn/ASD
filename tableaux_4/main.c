#include <stdio.h>

double P(int length, double a[length], double x);

int main(void)
{
    int length = 5;
    double a[] = {9.0, 5.0, 3.0, 0.0, 7.0};
    double x = 10.0;
    printf("%f : %f\n", x, P(length, a, x));
    return 0;
}

double P(int length, double a[length], double x)
{
    double result = 0;
    for(int i = 0; i < length; ++i)
    {
        double pui = 1.0;
        for (int j = i; j > 0; --j) pui *= x;
        result += a[i] * pui;
    }
    return result;
}

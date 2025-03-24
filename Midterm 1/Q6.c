#include <stdio.h>
#include <stdlib.h>

double power(double x, int y);

int main()
{
    double x, result = 0.0;
    int n;

    printf("Enter x and n to calculate ln(1+x). n is the number of terms in the summation.\n");
    scanf("%lf %d", &x, &n);

    for (int i = 1; i <= n; i++)
    {
        result +=  (power(x, i) * power(-1, i - 1)) / i;
    }
    
    printf("ln(%.2lf) = %.2lf\n", x + 1, result);

    return EXIT_SUCCESS;
}

double power(double x, int y)
{
    double result = 1.0;

    for (int i = 0; i < y; i++)
    {
        result *= x;
    }
    
    return result;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    double x = 0;
    double s;
    
    while (1)
    {
        s = 1.0 / (1 + n * n);
        n++;
        x = x + s;

        if (s <= 0.01) break;
    }

    printf("%lf", x);

    return EXIT_SUCCESS;
}
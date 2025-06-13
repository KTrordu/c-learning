#include "operations.h"

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

float divide(int a, int b)
{
    if (b == 0)
    {
        printf("Error: division by zero.\n");
        return EXIT_FAILURE;
    }
    return (float) a / b;
}
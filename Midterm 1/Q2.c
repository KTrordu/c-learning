#include <stdio.h>
#include <stdlib.h>

int mystery(int n);
int find_digits(int n);

int main()
{
    int n;
    printf("Enter: ");
    scanf("%d", &n);

    printf("Mystery: %d\n", mystery(n));
    printf("Digits: %d\n", find_digits(n));

    return EXIT_SUCCESS;
}

int mystery(int n)
{
    int x = n;
    while (x > 9)
    {
        x = x / 10;
    }
    return x;
}

int find_digits(int n)
{
    int x = n;
    int digits = 0;

    while (x != 0)
    {
        x /= 10;
        digits++;
    }
    
    return digits;
}
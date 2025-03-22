#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) 
{
    int k, temp, mod = 0, num1 = 1, num2 = 1;

    printf("Enter K: ");
    scanf("%d", &k);

    while (k != 0)
    {
        temp = num2;
        num2 += num1;
        num1 = temp;

        if (num2 % 3 == 0 && num2 % 10 != mod)
        {
            mod = num2 % 10;

            k--;

            if (k == 0) printf("%d", num2);
            else printf("%d, ", num2);
        }
    }

    return EXIT_SUCCESS;
}
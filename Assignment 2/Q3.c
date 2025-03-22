#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) 
{
    int x, steps = 0;
    
    printf("Enter the starting number: ");
    scanf("%d", &x);

    while (x != 1)
    {
        printf("%d -> ", x);

        if (x % 2 == 0) x /= 2;
        else x = (x * 3) + 1;

        steps++;
    }

    printf("%d\nSteps taken: %d", x, steps);

    return EXIT_SUCCESS;
}
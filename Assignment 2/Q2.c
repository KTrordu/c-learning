#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) 
{
    int knights, temp_knights, rounds = 1;
    printf("Enter the number of knights: ");
    scanf("%d", &knights);
    if (knights <= 0)
    {
        printf("The number of knights must be more than 0.\n");
        return EXIT_SUCCESS;
    }
    
    temp_knights = knights;
    while (temp_knights != 2)
    {
        if (temp_knights % 2 == 0)
        {
            printf("Round %d: %d knights fight, %d advance.\n", rounds, temp_knights, temp_knights / 2);
            temp_knights /= 2;
        }
        else
        {
            printf("Round %d: %d knights fight, %d advance (1 gets a bye).\n", rounds, temp_knights, (temp_knights / 2) + 1);
            temp_knights = (temp_knights / 2) + 1;
        }
        
        rounds++;
    }
    
    printf("Round %d: %d knights fight, 1 remains.\n", rounds, temp_knights);
    printf("Winner declared!\n");

    return EXIT_SUCCESS;
}
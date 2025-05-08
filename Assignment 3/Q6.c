#include <stdio.h>
#include <stdlib.h>

int main(){
    char grid[6][6] = { 
        {'A', 'B', 'C', 'A', 'E', 'F'}, 
        {'G', 'H', 'A', 'J', 'K', 'L'}, 
        {'M', 'N', 'O', 'A', 'Q', 'R'}, 
        {'S', 'T', 'U', 'V', 'W', 'X'}, 
        {'Y', 'Z', 'A', 'B', 'C', 'D'}, 
        {'E', 'F', 'G', 'H', 'A', 'J'} 
    };

    char letter = 'A';
    int counter = 0;

    //printf("Enter: ");
    //scanf("%c", &letter);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (grid[i][j] == letter)
            {
                counter++;
            }
        }
    }
    
    printf("%d", counter);

    return EXIT_SUCCESS;
}
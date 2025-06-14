#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fPtr;
    if ((fPtr = fopen("filled.txt", "r")) == NULL)
    {
        puts("The file could not be opened.\n");
    }
    else
    {
        printf("Enter a character: ");
        char choice;
        scanf("%c", &choice);

        int occurences = 0, position = 1, positions[4096];

        while (!feof(fPtr))
        {
            char letter = fgetc(fPtr);
            if (letter == choice)
            {
                positions[occurences] = position;
                occurences++;
            }
            
            if (letter != '\n')
            {
                position++;
            }
        }
        printf("This character occurs %d times in the following positions: ", occurences);
        for (int i = 0; i < occurences; i++)
        {
            printf("%d ", positions[i]);
        }
        
    }
    fclose(fPtr);

    return EXIT_SUCCESS;
}
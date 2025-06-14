#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fPtr;
    if ((fPtr = fopen(argv[1], "r")) == NULL)
    {
        puts("The file could not be opened.\n");
    }
    else
    {
        int space_count = 0;

        while (!feof(fPtr))
        {
            char letter = fgetc(fPtr);
            if (letter == ' ')
            {
                space_count++;
            }
        }
        printf("Number of spaces between the words are: %d", space_count);
    }
    fclose(fPtr);

    return EXIT_SUCCESS;
}
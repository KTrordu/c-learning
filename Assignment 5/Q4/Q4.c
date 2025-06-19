#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *dPtr, *dwPtr;
    if ((dwPtr = fopen("newData.txt", "w")) == NULL)
    {
        puts("newData.txt could not be opened.\n");
        return EXIT_FAILURE;
    }
    else
    {
        if ((dPtr = fopen("data.txt", "r")) == NULL)
        {
            puts("data.txt could not be opened.\n");
            return EXIT_FAILURE;
        }
        else
        {
            char line[1000];

            while(fgets(line, sizeof(line), dPtr))
            {
                line[strcspn(line, "\n")] = 0;

                for (int i = strlen(line) - 1; i >= 0; i--)
                {
                    fprintf(dwPtr, "%c", line[i]);
                }
                fprintf(dwPtr, "\n");
            }
        }
    }

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *lwPtr, *lrPtr;
    if ((lwPtr = fopen("errors.log", "w")) == NULL)
    {
        puts("errors.log could not be opened.\n");
        return EXIT_FAILURE;
    }
    else
    {
        if ((lrPtr = fopen("logs.log", "r")) == NULL)
        {
            puts("logs.log could not be opened.\n");
            return EXIT_FAILURE;
        }
        else
        {
            char line[1000];

            while(fgets(line, sizeof(line), lrPtr))
            {
                line[strcspn(line, "\n")] = 0;

                if (strstr(line, "[ERROR]"))
                {
                    fprintf(lwPtr, "%s\n", line);
                }
            }
        }
    }

    return EXIT_SUCCESS;
}
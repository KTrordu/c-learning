#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *mfPtr, *d1Ptr, *d2Ptr;

    int *nums = malloc(0);
    int count = 0;
    if (nums == NULL)
    {
        printf("An error occured.\n");
        return EXIT_FAILURE;
    }

    if ((mfPtr = fopen("merged.txt", "w")) == NULL)
    {
        puts("merged.txt could not be opened.\n");
        return EXIT_FAILURE;
    }
    else
    {
        if ((d1Ptr = fopen(argv[1], "r")) == NULL)
        {
            printf("%s could not be opened.\n", argv[1]);
            return EXIT_FAILURE;
        }
        else
        {
            while (!feof(d1Ptr))
            {
                count++;
                nums = realloc(nums, count * sizeof(int));

                fscanf(d1Ptr, "%d", &nums[count - 1]);
            }
        }
        fclose(d1Ptr);

        if ((d2Ptr = fopen(argv[2], "r")) == NULL)
        {
            printf("%s could not be opened.\n", argv[2]);
            return EXIT_FAILURE;
        }
        else
        {
            while (!feof(d2Ptr))
            {
                count++;
                nums = realloc(nums, count * sizeof(int));

                fscanf(d2Ptr, "%d", &nums[count - 1]);
            }
        }
        fclose(d2Ptr);
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(mfPtr, "%d\n", nums[i]);
    }
    fclose(mfPtr);

    return 0;
}
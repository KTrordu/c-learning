#include <stdio.h>
#include <stdlib.h>

void sortOddEven(int nums[], int size);

int main()
{
    int *nums = malloc(0);
    int number;
    int number_count = 0;
    printf("Provide the list of integers to be sorted:\n");

    while (1)
    {
        scanf("%d", &number);
        if (number == -1)
        {
            break;
        }
        number_count++;
        nums = realloc(nums, number_count * sizeof(int));

        nums[number_count - 1] = number;
    }

    sortOddEven(nums, number_count);
    free(nums);

    return EXIT_SUCCESS;
}

void sortOddEven(int nums[], int size)
{
    int sortedNums[size];
    int number_count = 0;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] % 2 == 1)
        {
            sortedNums[number_count] = nums[i];
            number_count++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (nums[i] % 2 == 0)
        {
            sortedNums[number_count] = nums[i];
            number_count++;
        }
    }

    printf("The sorted version:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sortedNums[i]);
    }
}
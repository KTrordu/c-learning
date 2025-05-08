#include <stdio.h>
#include <stdlib.h>

void printReversed(int* arr, int size);

int main(){
    int size;
    int *arr = NULL;

    printf("Enter number of integers: ");
    scanf("%d", &size);

    arr = (int*) malloc(size * sizeof(int));
    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }

    printf("Reversed order:\n");
    printReversed(arr, size);
    free(arr);

    return EXIT_SUCCESS;
}

void printReversed(int* arr, int size)
{
    int *ptr = arr + size - 1;

    for (int i = 0; i < size; i++)
    {
        printf("%d ", *ptr);
        ptr--;
    }
}
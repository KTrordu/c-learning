#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void analyzeTrend(int arr[], int n);

int main(){
    int n;
    int *ptr_n = NULL;

    printf("Enter number of days: ");
    scanf("%d", &n);

    ptr_n = (int*) malloc(n * sizeof(int));
    printf("Temperatures: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr_n[i]);
    }
    
    analyzeTrend(ptr_n, n);
    free(ptr_n);

    return EXIT_SUCCESS;
}

void analyzeTrend(int *arr, int n)
{
    bool is_inc = true;
    bool is_dec = true;

    for (int i = 1; i < n && is_inc; i++)
    {
        if (!(arr[i] > arr[i - 1])) is_inc = false;
    }

    if (is_inc) is_dec = false;
    else if(!is_inc)
    {
        for (int i = 1; i < n && is_dec; i++)
        {
            if (!(arr[i] < arr[i - 1])) is_dec = false;
        }
    }

    if (is_inc)
    {
        printf("Temperatures are increasing.");
    }
    else if (is_dec)
    {
        printf("Temperatures are decreasing.");
    }
    else
    {
        printf("No consistent trend.");
    }
}
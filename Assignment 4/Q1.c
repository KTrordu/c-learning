#include <stdio.h>
#include <stdlib.h>

void detectOutliers(int temps[], int n);

int main(){
    int n;
    int *ptr_n = NULL;

    printf("Enter the number of days: ");
    scanf("%d", &n);

    ptr_n = (int*) malloc(n * sizeof(int));

    printf("Enter temperatures: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr_n[i]);
    }
    
    detectOutliers(ptr_n, n);
    free(ptr_n);

    return EXIT_SUCCESS;
}

void detectOutliers(int *temps, int n)
{
    for (int i = 1; i < n; i++)
    {
        int diff = abs(temps[i] - temps[i - 1]);

        if (diff >= 10)
        {
            printf("Outlier at day %d: %d (difference from previous: %d)\n", i + 1, temps[i], diff);
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[] = {-10, -2, 5, 8, 10, 12, 13, 14, 16, 62};
    int p;
    float percent, arr_length = sizeof(arr) / sizeof(int), avg;
    float total = 0;

    printf("Enter: ");
    scanf("%d", &p);

    percent = (arr_length) * (p / 100.0);

    for (int i = percent; i < arr_length - percent; i++)
    {
        total += arr[i];
    }

    avg = total / arr_length;
    
    printf("Mean = %f", avg);

    return EXIT_SUCCESS;
}
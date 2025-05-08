#include <stdio.h>
#include <stdlib.h>

int main(){
    int N[] = {2, 5, 7, 9};
    int M[] = {1, 3, 6, 8, 11};

    int arr[9];
    int i = 0, j = 0, k = 0;

    while (i < 4 && j < 5)
    {
        if (N[i] < M[j])
        {
            arr[k++] = N[i++];
        }
        else
        {
            arr[k++] = M[j++];
        }
    }

    while (i < 4)
    {
        arr[k++] = N[i++];
    }
    
    while (j < 5)
    {
        arr[k++] = M[j++];
    }

    for (int i = 0; i < 9; i++)
    {
        printf("%d ", arr[i]);
    }
    

    return EXIT_SUCCESS;
}
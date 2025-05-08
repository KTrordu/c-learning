#include <stdio.h>
#include <stdlib.h>

void detectChanges(int scores[][2], int studentCount);

int data[6][2] = {
    {12, 24},
    {35, 47},
    {58, 69},
    {71, 83},
    {94, 15},
    {26, 37}
};

int main(){
    detectChanges(data, 6);

    return EXIT_SUCCESS;
}

void detectChanges(int scores[][2], int studentCount)
{
    for (int i = 0; i < 6; i++)
    {
        int diff = data[i][1] - data[i][0];
        printf("Student %d: %d ", i + 1, diff);

        if (diff > 15)
        {
            printf("Significant improvement\n");
        }
        else if (diff < -15)
        {
            printf("Significant drop\n");
        }
        else
        {
            printf("\n");
        }
    }
}
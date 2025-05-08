#include <stdio.h>
#include <stdlib.h>

void weeklyRainfall(int data[][4], int rows);

int main(){
    int data[5][4] = {
        {85, 90, 78, 92},
        {76, 88, 91, 83},
        {69, 72, 80, 75},
        {95, 94, 99, 98},
        {60, 65, 70, 68}
    };
    
    weeklyRainfall(data, 5);

    return EXIT_SUCCESS;
}

void weeklyRainfall(int data[][4], int rows)
{
    int weeks[] = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            weeks[i] += data[j][i];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        printf("Week %d: %d mm\n", i + 1, weeks[i]);
    }
}
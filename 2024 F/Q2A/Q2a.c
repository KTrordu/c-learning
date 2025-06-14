#include <stdio.h>
#include <stdlib.h>

#define NUMS_COUNT 3

void sort3d(int nums[3]);

int main()
{
    int a, b, c;
    int nums[3];

    printf("Enter three integers:\n");
    scanf("%d %d %d", &a, &b, &c);
    nums[0] = a;
    nums[1] = b;
    nums[2] = c;

    sort3d(nums);

    return EXIT_SUCCESS;
}

void sort3d(int nums[3])
{
    int a, b, c;
    int indices[3];

    a = nums[0];
    b = nums[1];
    c = nums[2];

    if (a >= b)
    {
        if (a >= c)
        {
            if (b >= c)
            {
                indices[0] = 2;
                indices[1] = 1;
                indices[2] = 0;
            }
            else
            {
                indices[0] = 1;
                indices[1] = 2;
                indices[2] = 0;
            }
        }
        else
        {
            indices[0] = 1;
            indices[1] = 0;
            indices[2] = 2;
        }
    }
    else
    {
        if (b >= c)
        {
            if (a >= c)
            {
                indices[0] = 2;
                indices[1] = 0;
                indices[2] = 1;
            }
            else
            {
                indices[0] = 0;
                indices[1] = 2;
                indices[2] = 1;
            }
        }
        else
        {
            indices[0] = 0;
            indices[1] = 1;
            indices[2] = 2;
        }
    }

    printf("The ordered indices:\n");
    for (int i = 0; i < NUMS_COUNT; i++)
    {
        printf("%d ", indices[i]);
    }
    
}
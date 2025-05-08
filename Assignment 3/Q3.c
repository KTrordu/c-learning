#include <stdio.h>
#include <stdlib.h>

int main(){
    int nums[] = {1, 5, 2, 1, 7, 5, 8, 2, 8, 7};
    int k = 4;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; i < 10; i++)
        {
            if (i == j) continue;

            if (nums[i] == nums[j])
            {
                if (abs(i - j) <= k)
                {
                    printf("True");
                }
            }
            
        }
        
    }

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>

struct Candidate { 
    char name[30]; 
    int votes; 
    };

int main(){
    struct Candidate candidates[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Enter name and vote for candidate %d: ", i + 1);
        scanf("%s %d", candidates[i].name, &candidates[i].votes);
    }
    
    int max_index = 0;
    for (int i = 1; i < 3; i++)
    {
        if (candidates[i].votes > candidates[max_index].votes)
        {
            max_index = i;
        }
    }

    printf("\nWinner is %s with %d votes.\n\n", candidates[max_index].name, candidates[max_index].votes);
    
    for (int i = 0; i < 3; i++)
    {
        printf("%s votes: %d\n", candidates[i].name, candidates[i].votes);
    }

    return EXIT_SUCCESS;
}
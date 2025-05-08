#include <stdio.h>
#include <stdlib.h>

struct Patient { 
    char name[30]; 
    int age; 
    float temp; 
};

int main(){
    struct Patient patients[4];

    for (int i = 0; i < 4; i++)
    {
        printf("Enter name, age and temperature for patient %d: ", i + 1);
        scanf("%s %d %f", patients[i].name, &patients[i].age, &patients[i].temp);
    }

    int max_index = 0;
    for (int i = 1; i < 4; i++)
    {
        if (patients[i].temp > patients[max_index].temp)
        {
            max_index = i;
        }
    }
    
    printf("Highest temperature is %s with %.2f. ", patients[max_index].name, patients[max_index].temp);

    return EXIT_SUCCESS;
}
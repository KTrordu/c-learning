#define DEBUG_MODE

#include "debug.h"
#include <stdlib.h>

#define STUDENTS_COUNT 5

#define IS_SUCCESSFUL(avg) ((avg) >= 60.0)

struct Student
{
    int id;
    char name[30];
    float grades[4];
    float average;
};

float calculate_average(float grades[4]);

int main()
{
    struct Student students[STUDENTS_COUNT];

    for (int i = 0; i < STUDENTS_COUNT; i++)
    {
        printf("Enter the id for the student number %d: ", i + 1);
        scanf("%d", &students[i].id);
        LOG("id entered.");

        printf("\nEnter the name for the student number %d: ", i + 1);
        scanf("%s", students[i].name);
        LOG("name entered.");

        printf("\nEnter the grade 1 for the student number %d: ", i + 1);
        scanf("%f", &students[i].grades[0]);
        LOG("grade 1 entered.");

        printf("\nEnter the grade 2 for the student number %d: ", i + 1);
        scanf("%f", &students[i].grades[1]);
        LOG("grade 2 entered.");

        printf("\nEnter the grade 3 for the student number %d: ", i + 1);
        scanf("%f", &students[i].grades[2]);
        LOG("grade 3 entered.");

        printf("\nEnter the grade 4 for the student number %d: ", i + 1);
        scanf("%f", &students[i].grades[3]);
        LOG("grade 4 entered.");

        printf("\n");
    }

    printf("Successful students: \n\n");
    
    for (int i = 0; i < STUDENTS_COUNT; i++)
    {
        if (IS_SUCCESSFUL(calculate_average(students[i].grades)))
        {
            printf("%s\n", students[i].name);
            LOG("names printed.");
        }
    }
    

    return EXIT_SUCCESS;
}

float calculate_average(float grades[4])
{
    return (grades[0] + grades[1] + grades[2] + grades[3]) / 4.0;
    LOG("averages calculated.");
}
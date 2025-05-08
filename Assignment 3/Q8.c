#include <stdio.h>
#include <stdlib.h>

int main(){
    int grades[6][4] = { 
        {75, 80, 70, 85}, 
        {90, 95, 88, 93}, 
        {60, 65, 70, 55}, 
        {100, 90, 95, 85}, 
        {45, 50, 40, 60}, 
        {85, 80, 75, 70} 
    };

    int total_grades[] = {0, 0, 0, 0, 0, 0};
    int max_grade;
    int max_stud;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            total_grades[i] += grades[i][j];
        }
    }
    
    max_grade = total_grades[0];
    max_stud = 0;
    for (int i = 1; i < 6; i++)
    {
        if (total_grades[i] > max_grade)
        {
            max_grade = total_grades[i];
            max_stud = i + 1;
        }
    }
    
    printf("Max = %d. student with %d. ", max_stud, max_grade);

    return EXIT_SUCCESS;
}
#include <stdio.h>

int main()
{
    int total;
    int x1;

    printf("Please enter a number: ");
    scanf("%d", &x1);

    total = total + x1; // total is not initialized

    printf("Please enter another number: ");

    int x2;

    scanf("%d", &x2);

    total = total + x1; // it should be total = x1 + x2;
    double average = total / 2; // it should be 2.0 instead of 2
    
    printf("The average of the two numbers is %f\n", average); // it should be %lf instead of %f

    return 0;
}
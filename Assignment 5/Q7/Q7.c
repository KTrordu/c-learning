#include "math_utils.h"
#include <stdlib.h>

float calculate_average(float grades[4]);

int main()
{
    float x, y;
    printf("Enter the x value: ");
    scanf("%f", &x);
    printf("Enter the y value: ");
    scanf("%f", &y);

    printf("\nx Squared: %f\n", SQUARE(x));
    printf("x Cubed: %f\n", CUBE(x));

    printf("\n%f is the bigger number.\n", MAX(x, y));
    
    printf("\nArea of the circle with radius x: %f\n", CIRCLE_AREA(x));

    printf("\nArea of the rectangle with the width and height of x and y: %f\n", RECTANGLE_AREA(x, y));

    printf("\nThe distance between (%f, %f) and (0, 0): %f\n", x, y, DISTANCE(x, y, 0, 0));

    return EXIT_SUCCESS;
}
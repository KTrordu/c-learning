#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

int main()
{
    double radius, diameter, circumference, area;

    radius = 3;
    diameter = 2 * radius;
    circumference = 2 * PI * radius;
    area = PI * radius * radius;

    printf("Diameter: %.2lf\n", diameter);
    printf("Circumference: %.2lf\n", circumference);
    printf("Area: %.2lf\n", area);

	return EXIT_SUCCESS;
}
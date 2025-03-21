#include <stdio.h>
#include <stdlib.h>

#define KM_H_CONSTANT 3.0/50.0

int main()
{
    unsigned int distance_traveled, time_taken;
    double speed;

    printf("Enter the distance traveled (in meters): ");
    scanf("%d", &distance_traveled);

    printf("Enter the time taken: ");
    scanf("%d", &time_taken);

    speed = (distance_traveled / time_taken) * KM_H_CONSTANT;
    printf("Average speed: %.2lf", speed);

	return EXIT_SUCCESS;
}
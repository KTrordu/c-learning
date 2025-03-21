#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int total_seconds;
    unsigned int hours = 0, minutes = 0, seconds = 0;
    
    printf("Enter the total seconds: ");
    scanf("%u", &total_seconds);

    while (total_seconds >= 3600)
    {
        total_seconds -= 3600;
        hours++;
    }

    while (total_seconds >= 60)
    {
        total_seconds -= 60;
        minutes++;
    }

    seconds = total_seconds;

    printf("Time: %d hour(s), %d minute(s), %d second(s)", hours, minutes, seconds);

	return EXIT_SUCCESS;
}
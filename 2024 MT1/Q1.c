#include <stdio.h>
#include <stdlib.h>

#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

int main()
{
    int hour1, hour2, minute1, minute2, second1, second2, total1, total2;

    printf("Enter time point t1: ");
    scanf("%d %d %d", &hour1, &minute1, &second1);

    printf("Enter time point t2: ");
    scanf("%d %d %d", &hour2, &minute2, &second2);

    total1 = hour1 * SECONDS_IN_HOUR + minute1 * SECONDS_IN_MINUTE + second1;
    total2 = hour2 * SECONDS_IN_HOUR + minute2 * SECONDS_IN_MINUTE + second2;

    if (total1 > total2)
    {
        printf("t1 > t2\n");
    }
    else if (total2 > total1)
    {
        printf("t2 > t1\n");
    }
    else
    {
        printf("t1 = t2\n");
    }

    return EXIT_SUCCESS;
}
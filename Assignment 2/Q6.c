#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define METERS_GRAVITY 9.81
#define FEET_GRAVITY 32.17

int main(int argc, char const *argv[]) 
{
    int unit;
    double initial_velocity, launch_angle, launch_angle_rad, h_velocity, v_velocity, t_total, hmax, gravity;

    printf("Choose unit of measurement:\n0 - Meters\n1 - Feet\n");
    printf("Enter your choice: ");
    scanf("%d", &unit);

    if (unit != 0 && unit != 1)
    {
        printf("Invalid input.\n");
        return EXIT_SUCCESS;
    }
    gravity = (unit == 0 ? METERS_GRAVITY : FEET_GRAVITY);
    
    printf("Enter initial velocity (%s/s): ", (unit == 0 ? "m" : "ft"));
    scanf("%lf", &initial_velocity);

    printf("Enter launch angle (degrees): ");
    scanf("%lf", &launch_angle);

    launch_angle_rad = launch_angle * (M_PI / 180.0);
    h_velocity = initial_velocity * cos(launch_angle_rad);
    v_velocity = initial_velocity * sin(launch_angle_rad);
    t_total = (2 * v_velocity) / gravity;
    hmax = (v_velocity * v_velocity) / (2 * gravity);

    if (unit == 0)
    {
        printf("Time (s) | Height (m) | Distance (m)\n");
        printf("------------------------------------\n");
        printf("0.00     | 0.00       | 0.00        \n");

        for (int i = 1; i <= t_total; i++)
        {
            printf("%d.00     | %-11.2lf| %-12.2lf\n", i, v_velocity * i - (0.5 * gravity * i * i), h_velocity * i);
        }

        printf("------------------------------------\n");
        printf("Maximum Height: %.2lf %s\n", hmax, (unit == 0 ? "m" : "ft"));
        printf("The projectile hit the ground at t = %.2lf s, x = %.2lf %s", t_total, h_velocity * t_total, (unit == 0 ? "m" : "ft"));
    }
    else
    {
        printf("Time (s) | Height (ft) | Distance (ft)\n");
        printf("--------------------------------------\n");
        printf("0.00     | 0.00        | 0.00        \n");

        for (int i = 1; i <= t_total; i++)
        {
            printf("%d.00     | %-12.2lf| %-13.2lf\n", i, v_velocity * i - (0.5 * gravity * i * i), h_velocity * i);
        }

        printf("------------------------------------\n");
        printf("Maximum Height: %.2lf %s\n", hmax, (unit == 0 ? "m" : "ft"));
        printf("The projectile hit the ground at t = %.2lf s, x = %.2lf %s", t_total, h_velocity * t_total, (unit == 0 ? "m" : "ft"));
    }
    
    return EXIT_SUCCESS;
}
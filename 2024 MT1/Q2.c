#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool is_descending;
    int current_num, prev_num;

    printf("Enter a number: ");
    scanf("%d", &current_num);
    prev_num = current_num;

    printf("Enter a number: ");
    scanf("%d", &current_num);

    if (current_num == prev_num) return EXIT_SUCCESS;
    else if (current_num < prev_num) is_descending = true;
    else is_descending = false;

    while (is_descending)
    {
        printf("Enter a number: ");
        scanf("%d", &current_num);

        if (current_num > prev_num) return EXIT_SUCCESS;
        prev_num = current_num;
    }

    while (!is_descending)
    {
        printf("Enter a number: ");
        scanf("%d", &current_num);

        if (current_num < prev_num) return EXIT_SUCCESS;
        prev_num = current_num;
    }

    return EXIT_SUCCESS;
}
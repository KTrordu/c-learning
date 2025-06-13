#include "operations.h"

// #define DEBUG

int main()
{
    int a, b;
    char operation;

    printf("Enter the numbers and the operation.\n");
    scanf("%d %d %c", &a, &b, &operation);

    #ifdef DEBUG

    printf("[DEBUG] Received inputs: a = %d, b = %d\n", a, b);
    printf("[DEBUG] Operation selected: %c\n", operation);

    #endif

    switch(operation)
    {
        case '+':
            #ifdef DEBUG

            printf("[DEBUG] Calling function: add(%d, %d)\n", a, b);
            printf("[DEBUG] Result: %d\n", add(a, b));

            #endif

            printf("%d\n", add(a, b));
            break;

        case '-':
            #ifdef DEBUG

            printf("[DEBUG] Calling function: sub(%d, %d)\n", a, b);
            printf("[DEBUG] Result: %d\n", sub(a, b));

            #endif

            printf("%d\n", sub(a, b));
            break;

        case '*':
            #ifdef DEBUG

            printf("[DEBUG] Calling function: mul(%d, %d)\n", a, b);
            printf("[DEBUG] Result: %d\n", add(a, b));

            #endif

            printf("%d\n", mul(a, b));
            break;

        case '/':
            #ifdef DEBUG

            printf("[DEBUG] Calling function: divide(%d, %d)\n", a, b);
            printf("[DEBUG] Result: %.2f\n", divide(a, b));

            #endif

            printf("%.2f\n", divide(a, b));
            break;
    }

    return EXIT_SUCCESS;
}
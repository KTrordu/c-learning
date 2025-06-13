#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 10

struct product
{
    char id[5];
    char name[13];
    double price;
    int stock;
};

int main(int argc, char *argv[])
{
    FILE *cPtr;

    struct product products[10];

    printf("\n%-8s%-15s%-9s%-9s%-13s\n", "ID", "Name", "Price", "Qty", "Total Value");
    printf("------------------------------------------------------\n");

    if ((cPtr = fopen("products.csv", "r")) == NULL)
    {
        puts("The file could not be opened.\n");
    }
    else
    {
        char line[1000];
        int line_number = 0;

        while (fgets(line, sizeof(line), cPtr) && line_number < ROW_SIZE)
        {
            line_number++;

            line[strcspn(line, "\n")] = 0;

            char *token = strtok(line, ",");

            if (token != NULL)
            {
                strcpy(products[line_number - 1].id, token);
                token = strtok(NULL, ",");

                if (token != NULL)
                {
                    strcpy(products[line_number - 1].name, token);
                    token = strtok(NULL, ",");

                    if (token != NULL)
                    {
                        products[line_number - 1].price = atof(token);
                        token = strtok(NULL, ",");

                        if(token != NULL)
                        {
                            products[line_number - 1].stock = atoi(token);
                        }
                    }
                }
                
            }
        }

        for (int i = 0; i < ROW_SIZE; i++)
        {
            printf("%-8s%-15s%-9.2lf%-9d%-13.2lf\n", products[i].id, products[i].name, products[i].price, products[i].stock, products[i].price * products[i].stock);
        }
        printf("------------------------------------------------------\n");
    }

    return EXIT_SUCCESS;
}
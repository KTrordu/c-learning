#include <stdio.h>
#include <stdlib.h>

struct Product { 
    char name[30]; 
    float price; 
};

void applyDiscount(struct Product* p); 

int main(){
    struct Product products[2];
    struct Product* p;

    for (int i = 0; i < 2; i++)
    {
        printf("Enter name and price for product %d: ", i + 1);
        scanf("%s %f", products[i].name, &products[i].price);
    }

    p = &products[0];
    applyDiscount(p);

    p = &products[1];
    applyDiscount(p);

    return EXIT_SUCCESS;
}

void applyDiscount(struct Product* p)
{
    p->price *= 0.9;
    printf("New price for product %s: %.2f\n", p->name, p->price);
}
#include <stdio.h>
#include <stdlib.h>

#define TAX_RATIO 7.5 / 100.0;
#define UNIT_SHIP_CHARGE 2

int main()
{
    int book_number;
    double total_book_price, tax, ship_charge, total_price;

    printf("Enter the total price of books: ");
    scanf("%lf", &total_book_price);

    printf("Enter the number of books: ");
    scanf("%d", &book_number);

    tax = total_book_price * TAX_RATIO;
    ship_charge = book_number * UNIT_SHIP_CHARGE;
    total_price = total_book_price + tax + ship_charge;

    printf("Total price: %.2lf", total_price);

    return EXIT_SUCCESS;
}
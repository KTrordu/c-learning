#include <stdio.h>
#include <stdlib.h>

#define ONE_TO_SEVEN_LATE_FEE 5
#define EIGHT_TO_TEN_LATE_FEE 10
#define MORE_THAN_TEN_LATE_FEE 15
#define MORE_THAN_ONE_MONTH_FEE 300

#define ONE_WEEK 7
#define THREE_DAYS 3

unsigned determine_fee(unsigned late_days);

int main()
{
    unsigned number_books, late_days, total_fee = 0;
    printf("Enter the number of books: ");
    scanf("%u", &number_books);

    for (int i = 1; i <= number_books; i++)
    {
        printf("Enter days late for book %d: ", i);
        scanf("%u", &late_days);

        total_fee += determine_fee(late_days);
    }
    
    printf("Total late fee for all books: %u.00", total_fee);

	return EXIT_SUCCESS;
}

unsigned determine_fee(unsigned late_days)
{
    if (late_days <= 7) {
        return late_days * ONE_TO_SEVEN_LATE_FEE;
    } else if (late_days <= 10) {
        return (ONE_WEEK * ONE_TO_SEVEN_LATE_FEE) + (late_days - ONE_WEEK) * EIGHT_TO_TEN_LATE_FEE;
    } else if (late_days <= 30) {
        return (ONE_WEEK * ONE_TO_SEVEN_LATE_FEE) + (THREE_DAYS * EIGHT_TO_TEN_LATE_FEE) + (late_days - ONE_WEEK - THREE_DAYS) * MORE_THAN_TEN_LATE_FEE;
    } else if (late_days > 30) {
        return MORE_THAN_ONE_MONTH_FEE;
    } else {
        printf("Invalid value.\n");
        return -1;
    }
}
#include <stdio.h>
#include <stdlib.h>

#define WEEKLY_PAYMENT 200
#define COMMISSION_RATIO 9.0/100.0

int main()
{
    int gross_sales;
    double commission, earning;

    printf("Enter gross sales for a week: ");
    scanf("%d", &gross_sales);

    commission = gross_sales * COMMISSION_RATIO;
    earning = WEEKLY_PAYMENT + commission;

    printf("Salesperson's earnings: %.2lf", earning);

	return EXIT_SUCCESS;
}
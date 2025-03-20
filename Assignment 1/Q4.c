#include <stdio.h>
#include <stdlib.h>

int main()
{
    int account_number;
    double begin_balance, total_charges, total_credits, credit_limit, new_balance;
    
    printf("Enter the account number: ");
    scanf("%d", &account_number);

    printf("Enter the beginning balance: ");
    scanf("%lf", &begin_balance);

    printf("Enter the total charges: ");
    scanf("%lf", &total_charges);

    printf("Enter the total credits: ");
    scanf("%lf", &total_credits);

    printf("Enter the credits limit: ");
    scanf("%lf", &credit_limit);

    new_balance = begin_balance + total_charges - total_credits;

    if(new_balance > credit_limit) {
        printf("Account: %d\n", account_number);
        printf("Credit limit: %.2lf\n", credit_limit);
        printf("Balance: %.2lf\n", new_balance);
        printf("Credit limit exceeded.\n");
    }

	return EXIT_SUCCESS;
}
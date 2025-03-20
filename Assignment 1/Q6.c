#include <stdio.h>
#include <stdlib.h>

#define BEGIN_BALANCE 500
#define MONEY_SYMBOL "TL"

int main()
{
    signed int balance;
    double transfer_money;
    balance = BEGIN_BALANCE;

    int decision;
    printf("Welcome to BEEbank!\n1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Exit\n");
    scanf("%d", &decision);

    switch (decision)
    {
    case 1:
        printf("Current balance: %d %s\n", balance, MONEY_SYMBOL);
        break;

    case 2:
        printf("Enter deposit amount: ");
        scanf("%lf", &transfer_money);

        printf("Deposited: %.2lf %s\n", transfer_money, MONEY_SYMBOL);
        printf("Current balance: %.2lf %s\n", (double)balance + transfer_money, MONEY_SYMBOL);
        break;

    case 3:
        printf("Enter withdrawal amount: ");
        scanf("%lf", &transfer_money);

        if(transfer_money <= balance){
            printf("Withdrawal successful!\n");
            printf("Current balance: %.2lf %s\n", (double)balance - transfer_money, MONEY_SYMBOL);
            break;
        }
        
        printf("Withdrawal amount cannot be greater than the balance.\n");
        break;

    case 4:
        break;

    default:
        printf("Invalid value.\n");
        break;
    }

	return EXIT_SUCCESS;
}
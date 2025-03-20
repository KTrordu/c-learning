#include <stdio.h>
#include <stdlib.h>

#define BEGIN_BALANCE 500
#define MONEY_SYMBOL "TL"

int main()
{
    int balance, transfer_money;
    balance = BEGIN_BALANCE;

    int decision;
    printf("Welcome to BEEbank!\n1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Exit\n");
    scanf("%d", &decision);

    switch (decision)
    {
    case 1:
        printf("Current balance: %d%s\n", balance, MONEY_SYMBOL);
        break;

    case 2:
        printf("Enter deposit amount: ");
        scanf("%d", &transfer_money);

        printf("Deposited: %d\n", transfer_money);
        printf("Current balance: %d\n", balance + transfer_money);
        break;

    case 3:
        printf("Enter withdrawal amount: ");
        scanf("%d", &transfer_money);

        printf("Withdrawal successful!\n");
        printf("Current balance: %d\n", balance - transfer_money);
        break;

    case 4:
        break;

    default:
        printf("Invalid value.\n");
        break;
    }

	return EXIT_SUCCESS;
}
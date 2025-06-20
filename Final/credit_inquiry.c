#include <stdio.h>

int main()
{
    FILE *cfPtr; // clients.txt pointer
    
    if ((cfPtr = fopen("clients.txt", "r")) == NULL)
    {
        puts("The file could not be opened.");
    }
    else
    {
        printf("%s", "Enter request\n"
            " 1 - List accounts with zero balances\n"
            " 2 - List accounts with credit balances\n"
            " 3 - List accounts with debit balances\n"
            " 4 - End of run\n? ");

        unsigned int request; // request number
        scanf("%u", &request);

        // process user's request
        while (request != 4)
        {
            unsigned int account;
            char name[30];
            double balance;

            fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);

            switch (request)
            {
            case 1:
                puts("\nAccounts with zero balances:");

                while (!feof(cfPtr))
                {
                    if (balance == 0)
                    {
                        printf("%-10d%-13s%7.2f\n", account, name, balance);
                    }

                    fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);
                }
                break;

            case 2:
                puts("\nAccounts with credit balances:");

                while (!feof(cfPtr))
                {
                    if (balance < 0)
                    {
                        printf("%-10d%-13s%7.2f\n", account, name, balance);
                    }

                    fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);
                }
                break;

            case 3:
                puts("\nAccounts with debit balances:");

                while (!feof(cfPtr))
                {
                    if (balance > 0)
                    {
                        printf("%-10d%-13s%7.2f\n", account, name, balance);
                    }

                    fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);
                }
                break;
            }

            rewind(cfPtr);

            printf("%s", "\n? ");
            scanf("%u", &request);
        }

        puts("End of run.\n");
        fclose(cfPtr);
    }

    return 0;
}
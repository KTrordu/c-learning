#include <stdio.h>

// clientData structure definition
struct clientData
{
    unsigned int accNum;
    char lastName[15];
    char firstName[10];
    double balance;
};

int main()
{
    FILE *cfPtr; // clients.txt pointer
    
    if ((cfPtr = fopen("accounts.dat", "rb+")) == NULL)
    {
        puts("The file could not be opened.");
    }
    else
    {
        struct clientData client = {0, "", "", 0};

        // require user to specify account number
        printf("%s", "Enter account number"
            " (1 to 100, 0 to end input): ");
        scanf("%d", &client.accNum);

        // user enters information, which is copied into file
        while (client.accNum != 0)
        {
            printf("%s", "\nEnter lastname, firstname, balance: ");

            // set record lastName, firstName and balance value
            fscanf(stdin, "%14s%9s%lf", client.lastName, client.firstName, &client.balance);

            // seek position in file to user-specified record
            fseek(cfPtr, (client.accNum - 1) * sizeof(struct clientData), SEEK_SET);

            // write user-specified information in file
            fwrite(&client, sizeof(struct clientData), 1, cfPtr);

            // enable user to enter another account number
            printf("%s", "\nEnter account number: ");
            scanf("%d", &client.accNum);
        }

        fclose(cfPtr);
    }
}
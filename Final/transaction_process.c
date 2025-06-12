#include <stdio.h>

struct clientData
{
    unsigned int acctNum;
    char lastName[15];
    char firstName[10];
    double balance;
};

unsigned int enterChoice();
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);

int main()
{
    FILE *cfPtr; // clients.txt pointer
    
    if ((cfPtr = fopen("accounts.dat", "rb+")) == NULL)
    {
        puts("The file could not be opened.");
    }
    else
    {
        unsigned int choice;

        while ((choice = enterChoice()) != 5)
        {
            switch (choice)
            {
            case 1:
                textFile(cfPtr);
                break;

            case 2:
                updateRecord(cfPtr);
                break;
            
            case 3:
                newRecord(cfPtr);
                break;

            case 4:
                deleteRecord(cfPtr);
                break;

            default:
                puts("Invalid choice.\n");
                break;
            }
        }
        fclose(cfPtr);
    }

    return 0;
}

void textFile(FILE *readPtr)
{
    FILE *writePtr;

    if ((writePtr = fopen("accounts.txt", "w")) == NULL)
    {
        puts("The file could not be opened.");
    }
    else
    {
        rewind(writePtr);
        fprintf(writePtr, "%-6s%-16s%-11s%10s\n", "Acct", "Firstname", "Lastname", "Balance");

        while (!feof(readPtr))
        {
            struct clientData client = {0, "", "", 0};

            int result = fread(&client, sizeof(struct clientData), 1, readPtr);

            if (result != 0 && client.acctNum != 0)
            {
                fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
            }
        }

        fclose(writePtr);
    }
}

void updateRecord(FILE *fPtr)
{
    printf("%s", "Enter account to update (1-100)");
    unsigned int accountNum;
    scanf("%u", &accountNum);

    fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);

    struct clientData client = {0, "", "", 0};

    fread(&client, sizeof(struct clientData), 1, fPtr);

    if (client.acctNum == 0)
    {
        printf("Account #%d has no information.\n", accountNum);
    }
    else
    {
        printf("%-6d%-16s%-11s%10.2lf\n\n", client.acctNum, client.lastName, client.firstName, client.balance);

        printf("%s", "Enter charge (+) or payment (-): ");
        double transaction;
        scanf("%lf", &transaction);

        client.balance += transaction;
        printf("%-6d%-16s%-11s%10.2lf\n\n", client.acctNum, client.lastName, client.firstName, client.balance);

        fseek(fPtr, (client.acctNum - 1) * sizeof(struct clientData), SEEK_SET);

        fwrite(&client, sizeof(struct clientData), 1, fPtr);
    }
}

void newRecord(FILE *fPtr)
{
    printf("%s", "Enter new account number (1-100)");
    unsigned int accountNum;
    scanf("%u", &accountNum);

    fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);

    struct clientData client = {0, "", "", 0};

    fread(&client, sizeof(struct clientData), 1, fPtr);

    if (client.acctNum != 0)
    {
        printf("Account #%d already contains information.\n", client.acctNum);
    }
    else
    {
        printf("%s", "Enter lastname, firstname and balance\n? ");
        scanf("%14s%9s%lf", client.lastName, client.firstName, &client.balance);

        client.acctNum = accountNum;

        fseek(fPtr, (client.acctNum - 1) * sizeof(struct clientData), SEEK_SET);

        fwrite(&client, sizeof(struct clientData), 1, fPtr);
    }
}

void deleteRecord(FILE *fPtr)
{
    printf("%s", "Enter account number to delete (1-100)");
    unsigned int accountNum;
    scanf("%u", &accountNum);

    fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);

    struct clientData client;

    fread(&client, sizeof(struct clientData), 1, fPtr);

    if (client.acctNum == 0)
    {
        printf("Account #%d does not exist.\n", accountNum);
    }
    else
    {
        fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);

        struct clientData blankClient = {0, "", "", 0};

        fwrite(&blankClient, sizeof(struct clientData), 1, fPtr);
    }
}

unsigned int enterChoice()
{
    printf("%s", "\nEnter your choice\n"
        "1 - store a formatted text file of accounts called\n"
        "   \"accounts.txt\" for printing\n"
        "2 - update an account\n"
        "3 - add a new account\n"
        "4 - delete an account\n"
        "5 - end program\n? ");

    unsigned menuChoice;
    scanf("%u", &menuChoice);
    return menuChoice;
}
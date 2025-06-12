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
    
    if ((cfPtr = fopen("accounts.dat", "rb")) == NULL)
    {
        puts("The file could not be opened.");
    }
    else
    {
        printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");

        // read all records from file (until eof)
        while (!feof(cfPtr))
        {
            // create clientData with default information
            struct clientData client = {0, "", "", 0};

            int result = fread(&client, sizeof(struct clientData), 1, cfPtr);

            // display record
            if (result != 0 && client.accNum != 0)
            {
                printf("%-6d%-16s%-11s%10.2f\n", client.accNum, client.lastName, client.firstName, client.balance);
            }
        }

        fclose(cfPtr);
    }
}
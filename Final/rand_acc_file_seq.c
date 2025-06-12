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
    
    if ((cfPtr = fopen("accounts.dat", "wb")) == NULL)
    {
        puts("The file could not be opened.");
    }
    else
    {
        struct clientData blankClient = {0, "", "", 0};

        // output 100 blank records to a file
        for (unsigned int i = 1; i <= 100; i++)
        {
            fwrite(&blankClient, sizeof(struct clientData), 1, cfPtr);
        }

        fclose(cfPtr);
    }
}
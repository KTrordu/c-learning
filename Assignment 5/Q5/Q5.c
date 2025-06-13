#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void input();
void display();

struct employeeData
{
    int id;
    char name[50];
    char department[50];
    float salary;
};

struct employeeData currentEmployee;

int main()
{
    FILE *ePtr;
    if ((ePtr = fopen("employees.dat", "ab+")) == NULL)
    {
        puts("employees.dat could not be opened.\n");
        return EXIT_FAILURE;
    }
    else
    {
        bool is_end = false;
        while (!is_end)
        {
            printf("%s", "\n1 - Add a new employee\n"
                "2 - List all employees\n"
                "3 - Search by ID\n"
                "4 - Exit\n\n");

            struct employeeData employee = {0, "", "", 0};

            unsigned int choice;
            scanf("%u", &choice);

            switch (choice)
            {
            case 1:
                input();
                fwrite(&currentEmployee, sizeof(struct employeeData), 1, ePtr);
                break;
            
            case 2:
                rewind(ePtr);
                printf("\n%-9s%-15s%-15s%-9s\n", "ID", "Name", "Department", "Salary");
                printf("------------------------------------------------\n");

                while (!feof(ePtr))
                {
                    int result = fread(&employee, sizeof(struct employeeData), 1, ePtr);

                    if (result != 0 && employee.id != 0)
                    {
                        currentEmployee.id = employee.id;
                        strcpy(currentEmployee.name, employee.name);
                        strcpy(currentEmployee.department, employee.department);
                        currentEmployee.salary = employee.salary;

                        display();
                    }
                }
                break;

            case 3:
                rewind(ePtr);
                int id;
                printf("Enter the employee's ID: ");
                scanf("%d", &id);

                bool is_found = false;
                
                while(!feof(ePtr))
                {
                    int result = fread(&employee, sizeof(struct employeeData), 1, ePtr);

                    if (result != 0 && employee.id == id)
                    {
                        is_found = true;

                        currentEmployee.id = employee.id;
                        strcpy(currentEmployee.name, employee.name);
                        strcpy(currentEmployee.department, employee.department);
                        currentEmployee.salary = employee.salary;

                        printf("\n%-9s%-15s%-15s%-9s\n", "ID", "Name", "Department", "Salary");
                        printf("------------------------------------------------\n");
                        display();
                    }
                }
                if (!is_found)
                {
                    printf("There is no employee with the ID: %d\n", id);
                }
                break;

            case 4:
                printf("Exiting the program.\n");
                is_end = true;
                break;

            default:
                printf("Invalid value.\n");
                break;
            }
        }
    }
    fclose(ePtr);

    return EXIT_SUCCESS;
}

void input()
{
    printf("Enter ID, name, department and salary.\n");
    scanf("%d%s%s%f", &currentEmployee.id, currentEmployee.name, currentEmployee.department, &currentEmployee.salary);
}

void display()
{
    printf("%-9d%-15s%-15s%-9.2f\n", currentEmployee.id, currentEmployee.name, currentEmployee.department, currentEmployee.salary);
}
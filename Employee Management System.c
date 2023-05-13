#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[100];
    int age;
    float salary;
};

void addEmployee(struct Employee *employees, int *count) {
    if (*count >= 100) {
        printf("Employee database is full. Cannot add more employees.\n");
        return;
    }

    struct Employee newEmployee;

    printf("Enter employee details:\n");
    printf("Employee ID: ");
    scanf("%d", &newEmployee.id);
    printf("Employee Name: ");
    scanf(" %[^\n]", newEmployee.name);
    printf("Employee Age: ");
    scanf("%d", &newEmployee.age);
    printf("Employee Salary: ");
    scanf("%f", &newEmployee.salary);

    employees[*count] = newEmployee;
    (*count)++;

    printf("Employee added successfully.\n");
}

void updateEmployee(struct Employee *employees, int count) {
    int employeeId;
    int found = 0;

    printf("Enter the employee ID to update: ");
    scanf("%d", &employeeId);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == employeeId) {
            printf("Enter new details for the employee:\n");
            printf("Employee Name: ");
            scanf(" %[^\n]", employees[i].name);
            printf("Employee Age: ");
            scanf("%d", &employees[i].age);
            printf("Employee Salary: ");
            scanf("%f", &employees[i].salary);

            printf("Employee details updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

void deleteEmployee(struct Employee *employees, int *count) {
    int employeeId;
    int found = 0;

    printf("Enter the employee ID to delete: ");
    scanf("%d", &employeeId);

    for (int i = 0; i < *count; i++) {
        if (employees[i].id == employeeId) {
            for (int j = i; j < *count - 1; j++) {
                employees[j] = employees[j + 1];
            }

            (*count)--;
            printf("Employee deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

void displayEmployees(struct Employee *employees, int count) {
    if (count == 0) {
        printf("Employee database is empty.\n");
        return;
    }

    printf("Employee Database:\n");
    printf("ID\tName\tAge\tSalary\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
    }
}

int main() {
    struct Employee employees[100];
    int count = 0;
    int choice;

    printf("Employee Management System\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add an employee\n");
        printf("2. Update an employee\n");
        printf("3. Delete an employee\n");
        printf("4. Display employees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                updateEmployee(employees, count);
                break;
            case 3:
                deleteEmployee(employees, &count);
                break;
            case 4:
                displayEmployees(employees, count);
                break;
            case 5:
                printf("Exiting Employee Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}

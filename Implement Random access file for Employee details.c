#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int empId;
    char empName[50];
    float empSalary;
};

void addEmployee(FILE *file) {
    struct Employee emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.empId);

    printf("Enter Employee Name: ");
    scanf("%s", emp.empName);

    printf("Enter Employee Salary: ");
    scanf("%f", &emp.empSalary);

    fseek(file, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp, sizeof(struct Employee), 1, file);

    printf("Employee added successfully.\n");
}

void displayEmployee(FILE *file) {
    struct Employee emp;
    int empId;

    printf("Enter Employee ID to display: ");
    scanf("%d", &empId);

    fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, file);

    printf("Employee ID: %d\n", emp.empId);
    printf("Employee Name: %s\n", emp.empName);
    printf("Employee Salary: %.2f\n", emp.empSalary);
}

void updateEmployee(FILE *file) {
    struct Employee emp;
    int empId;

    printf("Enter Employee ID to update: ");
    scanf("%d", &empId);

    fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, file);

    printf("Enter new Employee Name: ");
    scanf("%s", emp.empName);

    printf("Enter new Employee Salary: ");
    scanf("%f", &emp.empSalary);

    fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp, sizeof(struct Employee), 1, file);

    printf("Employee updated successfully.\n");
}

void deleteEmployee(FILE *file) {
    struct Employee emp;
    int empId;

    printf("Enter Employee ID to delete: ");
    scanf("%d", &empId);

    fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, file);

    emp.empId = 0; // Marking the record as deleted

    fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp, sizeof(struct Employee), 1, file);

    printf("Employee deleted successfully.\n");
}

int main() {
    FILE *file = fopen("employee.dat", "r+");

    if (file == NULL) {
        file = fopen("employee.dat", "w+");
        if (file == NULL) {
            printf("Error creating file!\n");
            return 1;
        }
    }

    int choice;

    do {
        printf("\nEmployee Database Menu:\n");
        printf("1. Add Employee\n");
        printf("2. Display Employee\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                displayEmployee(file);
                break;
            case 3:
                updateEmployee(file);
                break;
            case 4:
                deleteEmployee(file);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    fclose(file);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50
#define FILENAME "employees.dat"

// Structure to represent an employee
struct Employee {
int id;
char name[MAX_NAME_LENGTH];
float salary;
};

// Function to add a new employee record to the file
void addEmployee() {
FILE *file = fopen(FILENAME, "ab");
if (file == NULL) {
perror("Error opening file");
exit(EXIT_FAILURE);
}

struct Employee emp;

printf("Enter employee ID: ");
scanf("%d", &emp.id);
printf("Enter employee name: ");
scanf("%s", emp.name);
printf("Enter employee salary: ");
scanf("%f", &emp.salary);

fwrite(&emp, sizeof(struct Employee), 1, file);

fclose(file);

printf("Employee added successfully!\n");
}

// Function to search for an employee record by ID
void searchEmployee() {
FILE *file = fopen(FILENAME, "rb");
if (file == NULL) {
perror("Error opening file");
exit(EXIT_FAILURE);
}

int targetId;
printf("Enter employee ID to search: ");
scanf("%d", &targetId);

struct Employee emp;
int found = 0;
while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
if (emp.id == targetId) {
found = 1;
printf("Employee found!\n");
printf("ID: %d\n", emp.id);
printf("Name: %s\n", emp.name);
printf("Salary: %.2f\n", emp.salary);
break;
}
}

if (!found) {
printf("Employee not found!\n");
}

fclose(file);
}

// Function to update an existing employee record
void updateEmployee() {
FILE *file = fopen(FILENAME, "r+b");
if (file == NULL) {
perror("Error opening file");
exit(EXIT_FAILURE);
}

int targetId;
printf("Enter employee ID to update: ");
scanf("%d", &targetId);

struct Employee emp;
int found = 0;
while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
if (emp.id == targetId) {
found = 1;
printf("Enter new name: ");
scanf("%s", emp.name);
printf("Enter new salary: ");
scanf("%f", &emp.salary);

fseek(file, -sizeof(struct Employee), SEEK_CUR);
fwrite(&emp, sizeof(struct Employee), 1, file);
printf("Employee updated successfully!\n");
break;
}
}

if (!found) {
printf("Employee not found!\n");
}

fclose(file);
}

// Function to delete an existing employee record
void deleteEmployee() {
FILE *file = fopen(FILENAME, "r+b");
if (file == NULL) {
perror("Error opening file");
exit(EXIT_FAILURE);
}

int targetId;
printf("Enter employee ID to delete: ");
scanf("%d", &targetId);

struct Employee emp;
int found = 0;
while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
if (emp.id == targetId) {
found = 1;
emp.id = -1; // Marking as deleted
fseek(file, -sizeof(struct Employee), SEEK_CUR);
fwrite(&emp, sizeof(struct Employee), 1, file);
printf("Employee deleted successfully!\n");
break;
}
}

if (!found) {
printf("Employee not found!\n");
}

fclose(file);
}

// Main function to demonstrate the functionality
int main() {
int choice;
do {
printf("\nEmployee Management System\n");
printf("1. Add Employee\n");
printf("2. Search Employee\n");
printf("3. Update Employee\n");
printf("4. Delete Employee\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
addEmployee();
break;
case 2:
searchEmployee();
break;
case 3:
updateEmployee();
break;
case 4:
deleteEmployee();
break;
case 5:
printf("Exiting...\n");
break;
default:
printf("Invalid choice! Please try again.\n");
}
} while (choice != 5);

return 0;
}


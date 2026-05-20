#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student *next;
};

struct Student *head = NULL;

// Function to add student
void addStudent() {
    struct Student *newStudent, *temp;

    newStudent = (struct Student*)malloc(sizeof(struct Student));

    printf("\nEnter Roll Number: ");
    scanf("%d", &newStudent->roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent->name);

    printf("Enter Marks: ");
    scanf("%f", &newStudent->marks);

    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }

    printf("\nStudent Added Successfully!\n");
}

// Function to display students
void displayStudents() {
    struct Student *temp = head;

    if (head == NULL) {
        printf("\nNo Student Records Found!\n");
        return;
    }

    printf("\n===== STUDENT RECORDS =====\n");

    while (temp != NULL) {
        printf("\nRoll Number : %d", temp->roll);
        printf("\nName        : %s", temp->name);
        printf("\nMarks       : %.2f\n", temp->marks);

        temp = temp->next;
    }
}

// Function to search student
void searchStudent() {
    int roll;
    struct Student *temp = head;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", temp->roll);
            printf("Name        : %s\n", temp->name);
            printf("Marks       : %.2f\n", temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("\nStudent Not Found!\n");
}

// Function to delete student
void deleteStudent() {
    int roll;
    struct Student *temp = head, *prev = NULL;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    if (temp != NULL && temp->roll == roll) {
        head = temp->next;
        free(temp);
        printf("\nStudent Deleted Successfully!\n");
        return;
    }

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nStudent Not Found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("\nStudent Deleted Successfully!\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                printf("\nExiting Program...\n");
                exit(0);

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }

    return 0;
}

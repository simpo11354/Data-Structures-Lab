#include <stdio.h>
#include <stdlib.h>

// Define a struct to store student information
struct Student {
    int number;
    char name[50];
    int age;
    int studentID;
    struct Student* next;
};

// Function to create a new student node
struct Student* createStudent(int number, const char* name, int age, int studentID) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->number = number;
    snprintf(newStudent->name, sizeof(newStudent->name), "%s", name);
    newStudent->age = age;
    newStudent->studentID = studentID;
    newStudent->next = NULL;
    return newStudent;
}

// Function to add a new student to the end of the list
void addStudent(struct Student** head, struct Student* newStudent) {
    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
}

// Function to print and count the students
void printStudents(struct Student* head) {
    struct Student* current = head;
    int count = 1;

    while (current != NULL) {
        printf("%d - %s %d %d\n", current->number, current->name, current->age, current->studentID);
        current = current->next;
        count++;
    }

    printf("Total Students: %d\n", count - 1);
}

// Function to free the memory allocated for the list
void freeList(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        struct Student* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Student* head = NULL;

    // Add students to the list
    addStudent(&head, createStudent(1, "Saliha", 27, 201));
    addStudent(&head, createStudent(2, "Ece", 19, 203));

    // Print and count the students
    printStudents(head);

    // Free the memory allocated for the list
    freeList(head);

    return 0;
}

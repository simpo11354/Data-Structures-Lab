#include <stdio.h>
#include <string.h>

// Define a structure to represent a student record
struct Student {
    char name[50];
    int rollNumber;
    // Add more fields as needed
};

// Function to search for a student by name in a list of records
void searchStudentByName(struct Student records[], int numRecords, const char searchName[]) {
    int found = 0; // Flag to indicate if the student was found
    for (int i = 0; i < numRecords; i++) {
        // Compare the input name with the name in the current record
        if (strcmp(records[i].name, searchName) == 0) {
            // If names match, print the details of the student
            printf("Student found:\n");
            printf("Name: %s\n", records[i].name);
            printf("Roll Number: %d\n", records[i].rollNumber);
            // Add more fields as needed
            found = 1;
            break; // Exit the loop as we've found the student
        }
    }
    if (!found) {
        printf("Student with name %s not found in the list.\n", searchName);
    }
}

int main() {
    // Example student records
    struct Student records[] = {
        {"Alice", 101},
        {"Bob", 102},
        {"Charlie", 103},
        // Add more records as needed
    };

    int numRecords = sizeof(records) / sizeof(records[0]);

    char searchName[50];
    printf("Enter the name of the student you want to search for: ");
    scanf("%s", searchName);

    // Call the search function
    searchStudentByName(records, numRecords, searchName);

    return 0;
}

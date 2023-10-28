#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Define a structure to represent a record
struct Record {
    char name[MAX_NAME_LENGTH];
    int age;  // You can add more fields if needed
};

// Function to find and print the record with the longest name
void printLongestNameRecord(struct Record records[], int numRecords) {
    int longestLength = 0;  // Initialize to 0
    char longestName[MAX_NAME_LENGTH];

    for (int i = 0; i < numRecords; i++) {
        int currentLength = strlen(records[i].name);

        if (currentLength > longestLength) {
            longestLength = currentLength;
            strcpy(longestName, records[i].name);
        }
    }

    printf("The longest name in the list: %s\n", longestName);
    printf("Length: %d\n", longestLength);
}

int main() {
    struct Record records[] = {
        {"John Smith", 30},
        {"Jane Doe", 25},
        {"Abdurrahmangazi", 40},
        // Add more records as needed
    };

    int numRecords = sizeof(records) / sizeof(records[0]);

    printLongestNameRecord(records, numRecords);

    return 0;
}

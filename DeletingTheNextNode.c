#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student node
struct StudentNode {
    char name[50];
    int id;
    struct StudentNode* next;
};

// Function to delete the next node after finding the target student name
void deleteNextNode(struct StudentNode* head, const char* targetName) {
    if (head == NULL || targetName == NULL) {
        return;
    }

    struct StudentNode* current = head;

    while (current != NULL && current->next != NULL) {
        if (strcmp(current->name, targetName) == 0) {
            // Found the target node, so delete the next node
            struct StudentNode* temp = current->next;
            current->next = current->next->next;
            free(temp); // Free memory of the deleted node
            return;
        }
        current = current->next;
    }
}

// Function to print the linked list
void printList(struct StudentNode* head) {
    struct StudentNode* current = head;
    while (current != NULL) {
        printf("Name: %s, ID: %d\n", current->name, current->id);
        current = current->next;
    }
}

// Example usage
int main() {
    // Create a sample linked list
    struct StudentNode* head = (struct StudentNode*)malloc(sizeof(struct StudentNode));
    strcpy(head->name, "Alice");
    head->id = 1;
    head->next = NULL;

    struct StudentNode* node1 = (struct StudentNode*)malloc(sizeof(struct StudentNode));
    strcpy(node1->name, "Bob");
    node1->id = 2;
    node1->next = NULL;
    head->next = node1;

    struct StudentNode* node2 = (struct StudentNode*)malloc(sizeof(struct StudentNode));
    strcpy(node2->name, "Charlie");
    node2->id = 3;
    node2->next = NULL;
    node1->next = node2;

    printf("Original List:\n");
    printList(head);

    // Delete the node after "Bob"
    deleteNextNode(head, "Bob");

    printf("\nList after deleting the next node after 'Bob':\n");
    printList(head);

    // Free allocated memory
    struct StudentNode* current = head;
    while (current != NULL) {
        struct StudentNode* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* addNode(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int num;

    while (1) {
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        if (num % 2 == 1) {
            head = addNode(head, num);
        } else {
            struct Node* current = head;
            if (current == NULL) {
                head = addNode(head, num);
            } else {
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = addNode(NULL, num);
            }
        }
    }

    printf("Final List:\n");
    printList(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node* head = NULL; // Points to the first node
    struct Node* tail = NULL; // Points to the last node for easy appending

    // 2. Create the Linked List
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        // Allocate memory for a new node
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        // If list is empty, make newNode the head and tail
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } 
        // Otherwise, attach it to the tail and update the tail pointer
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 3. Traverse and Print the Linked List
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next; // Move to the next node
    }

    // Good practice: Free the allocated memory (Optional for simple competitive programming)
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
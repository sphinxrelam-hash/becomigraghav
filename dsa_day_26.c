#include <stdio.h>
#include <stdlib.h>

// 1. Define the Doubly Linked List Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    int n;
    
    // Read the number of elements
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    // 2. Build the Doubly Linked List
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        // Allocate memory for the new node
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            // First node: no previous node exists
            newNode->prev = NULL;
            head = tail = newNode;
        } else {
            // Link the new node to the tail, and tail back to the new node
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode; // Update tail to the new end of the list
        }
    }

    // 3. Forward Traversal
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // 4. Free allocated memory (Good practice!)
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
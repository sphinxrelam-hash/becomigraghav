#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    
    // Read the number of elements
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    // 1. Build the Circular Linked List
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;

        if (head == NULL) {
            // First node points to itself!
            head = newNode;
            tail = newNode;
            newNode->next = head; 
        } else {
            // Attach new node, update tail, and close the loop
            tail->next = newNode;
            tail = newNode;
            tail->next = head; 
        }
    }

    // 2. Traverse the Circular Linked List
    if (head != NULL) {
        struct Node* current = head;
        
        // A do-while loop is perfect here! 
        // It runs at least once, then stops when we wrap back to the start.
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    }

    // 3. Free the allocated memory (Good practice!)
    if (head != NULL) {
        struct Node* current = head;
        struct Node* nextNode;
        do {
            nextNode = current->next;
            free(current);
            current = nextNode;
        } while (current != head); // Stop freeing when we reach the start again
    }

    return 0;
}
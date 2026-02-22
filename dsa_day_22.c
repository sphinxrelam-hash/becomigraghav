#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    // 1. Create the Linked List
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 2. Traverse and Count the Nodes
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        printf("%d ", current->data); // Print to match example output
        count++;                      // Count the nodes as requested by title
        current = current->next;
    }
    
    // The variable 'count' now holds the total number of nodes (n)

    return 0;
}
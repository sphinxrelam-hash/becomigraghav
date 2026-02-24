#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key;
    
    // 1. Read size and create the list
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 2. Read the key to delete
    if (scanf("%d", &key) != 1) return 0;

    // 3. Delete First Occurrence using Dummy Node
    struct Node dummy;
    dummy.next = head;
    
    struct Node* prev = &dummy;
    struct Node* curr = head;

    while (curr != NULL) {
        if (curr->data == key) {
            prev->next = curr->next; // Bypass the target node
            free(curr);              // Free allocated memory
            break;                   // Stop after first deletion!
        }
        prev = curr;
        curr = curr->next;
    }

    // Update the real head (in case the original head was deleted)
    head = dummy.next;

    // 4. Print the modified list
    curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    return 0;
}
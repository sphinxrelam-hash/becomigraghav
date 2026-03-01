#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    
    // 1. Read size and build the list
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

    // 2. Read rotation count (k)
    int k;
    if (scanf("%d", &k) != 1) return 0;

    // 3. Rotation Logic
    if (head != NULL && head->next != NULL && k > 0) {
        
        // Find the length and the current tail
        int len = 1;
        struct Node* current = head;
        while (current->next != NULL) {
            len++;
            current = current->next;
        }

        // Optimize k in case it is larger than the list length
        k = k % len;
        
        if (k > 0) {
            // Connect tail to head to form a circular list
            current->next = head;

            // Find the node that will become the NEW tail
            int stepsToNewTail = len - k;
            struct Node* newTail = head;
            for (int i = 1; i < stepsToNewTail; i++) {
                newTail = newTail->next;
            }

            // The node after the new tail is the new head
            head = newTail->next;
            
            // Break the circle
            newTail->next = NULL;
        }
    }

    // 4. Print the rotated list
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // 5. Clean up memory
    temp = head;
    while (temp != NULL) {
        struct Node* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }

    return 0;
}
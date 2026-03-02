#include <stdio.h>
#include <stdlib.h>

// 1. Upgrade the Node structure for polynomials
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

int main() {
    int n;
    
    // Read the number of terms
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *tail = NULL;

    // 2. Build the Polynomial Linked List
    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->exp = e;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 3. Traverse and Print in Standard Form
    struct Node* current = head;
    while (current != NULL) {
        
        // Print the term based on the exponent
        if (current->exp == 0) {
            printf("%d", current->coeff);
        } else if (current->exp == 1) {
            printf("%dx", current->coeff);
        } else {
            printf("%dx^%d", current->coeff, current->exp);
        }
        
        // Print the "+" separator ONLY if there is a next term
        if (current->next != NULL) {
            printf(" + ");
        }
        
        current = current->next;
    }
    printf("\n");

    // 4. Clean up memory
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
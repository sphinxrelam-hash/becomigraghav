#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for our Linked List Stack
struct Node {
    int data;
    struct Node* next;
};

// Push an element to the top of the stack
void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *top_ref;
    *top_ref = new_node; 
}

// Pop an element from the top of the stack
int pop(struct Node** top_ref) {
    if (*top_ref == NULL) {
        return 0; // Stack empty
    }
    struct Node* temp = *top_ref;
    int popped_val = temp->data;
    *top_ref = temp->next;
    
    free(temp); // Free the memory!
    return popped_val;
}

int main() {
    struct Node* stack = NULL;
    char expr[100];

    // Read the postfix expression
    // Example input: 2 3 1 * + 9 -
    fgets(expr, sizeof(expr), stdin);

    int i = 0;
    while (expr[i] != '\0') {
        // Skip spaces and newlines
        if (expr[i] == ' ' || expr[i] == '\n') {
            i++;
            continue;
        }

        // If it's a number, extract it (handles multi-digit numbers) and push
        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            push(&stack, num);
        } 
        // If it's an operator, pop top two elements, apply operator, and push result
        else {
            int val1 = pop(&stack); // Top element (right operand)
            int val2 = pop(&stack); // Second top element (left operand)

            switch (expr[i]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': push(&stack, val2 / val1); break;
            }
            i++;
        }
    }

    // The final result is the only number left in the stack
    printf("%d\n", pop(&stack));

    return 0;
}
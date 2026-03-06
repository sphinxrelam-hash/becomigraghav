#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the linked list node for the stack
struct Node {
    int data;
    struct Node* next;
};

// Push: Allocate memory dynamically and add to top
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return; // Allocation failed
    
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop: Remove top node, free memory, and return value
int pop(struct Node** top) {
    if (*top == NULL) return 0; // Stack underflow
    
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    
    free(temp); // Prevent memory leaks
    return val;
}

// Evaluate the postfix expression
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    
    // Tokenize string by spaces
    char* token = strtok(exp, " \n");
    
    while (token != NULL) {
        // If token is a number (handles negative numbers too)
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        } 
        // If token is an operator
        else {
            // Order matters: pop right operand first, then left operand
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            
            switch (token[0]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break; // Truncates toward zero naturally
            }
        }
        // Get the next token
        token = strtok(NULL, " \n");
    }
    
    // The final result is the only item left on the stack
    return pop(&stack);
}

int main() {
    char expression[] = "2 3 1 * + 9 -";
    
    // Note: strtok modifies the original string, so we pass a mutable char array
    printf("Postfix Expression: %s\n", "2 3 1 * + 9 -");
    printf("Result: %d\n", evaluatePostfix(expression)); // Expected: -4
    
    return 0;
}
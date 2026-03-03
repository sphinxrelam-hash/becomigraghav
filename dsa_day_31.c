#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 

// Global array and top indicator
int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

// Function to pop the top element
void pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top]);
        top--;
    }
}

// Function to display the stack from top to bottom
void display() {
    if (top < 0) {
        return; // Stack is empty, nothing to display
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, type, value;
    
    // Read the total number of operations
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    // Loop through each operation
    for (int i = 0; i < n; i++) {
        scanf("%d", &type);
        
        if (type == 1) {
            scanf("%d", &value);
            push(value);
        } else if (type == 2) {
            pop();
        } else if (type == 3) {
            display();
        }
    }

    return 0;
}
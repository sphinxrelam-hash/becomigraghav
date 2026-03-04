#include <stdio.h>

int main() {
    int n;
    
    // 1. Read the number of elements to push
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    // Initialize our stack array and top pointer
    int stack[n];
    int top = -1;

    // 2. Read 'n' elements and push them onto the stack
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        // Increment top, then insert the value
        stack[++top] = val; 
    }

    int m;
    // 3. Read the number of elements to pop
    if (scanf("%d", &m) == 1) {
        // Pop 'm' times
        for (int i = 0; i < m; i++) {
            // Check for Stack Underflow (prevent popping if empty)
            if (top >= 0) {
                top--; 
            }
        }
    }

    // 4. Print remaining elements from top to bottom
    if (top == -1) {
        printf("Stack Underflow\n"); // Optional, but good practice
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

// Returns precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char* exp) {
    char stack[1000]; 
    int top = -1;
    
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        
        // Manual check for operands (A-Z, a-z, 0-9)
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            printf("%c", c);
        } 
        // Push '(' to stack
        else if (c == '(') {
            stack[++top] = c;
        } 
        // Pop and output until '(' is found
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            top--; // Discard the '('
        } 
        // Handle operators
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                printf("%c", stack[top--]);
            }
            stack[++top] = c; // Push current operator
        }
    }
    
    // Pop all remaining operators
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");
}

int main() {
    char exp[1000];
    
    // Read infix expression
    scanf("%s", exp); 
    
    // Convert and print
    infixToPostfix(exp); 
    
    return 0;
}
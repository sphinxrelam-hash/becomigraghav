#include <stdio.h>

#define MAX 100
int queue[MAX], stack[MAX];
int front = 0, rear = 0, top = -1;

void enqueue(int val) { queue[rear++] = val; }
int dequeue() { return queue[front++]; }
void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }
int isQueueEmpty() { return front == rear; }
int isStackEmpty() { return top == -1; }

int main() {
    int n, val;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }
    
    // Transfer from queue to stack
    while (!isQueueEmpty()) push(dequeue());
    
    // Transfer from stack back to queue
    front = rear = 0; // Reset queue pointers for simplicity
    while (!isStackEmpty()) enqueue(pop());
    
    for (int i = front; i < rear; i++) printf("%d ", queue[i]);
    return 0;
}
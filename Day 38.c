#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check if deque is empty
int empty() {
    return (front == -1);
}

// Insert at the rear
void push_back(int value) {
    if (front == -1) front = 0;
    deque[++rear] = value;
}

// Insert at the front
void push_front(int value) {
    if (front == -1) {
        front = rear = 0;
        deque[front] = value;
    } else if (front > 0) {
        deque[--front] = value;
    }
}

// Remove from the front
void pop_front() {
    if (!empty()) {
        if (front == rear) front = rear = -1;
        else front++;
    }
}

// Remove from the rear
void pop_back() {
    if (!empty()) {
        if (front == rear) front = rear = -1;
        else rear--;
    }
}

int get_front() { return empty() ? -1 : deque[front]; }
int get_back() { return empty() ? -1 : deque[rear]; }
int size() { return empty() ? 0 : rear - front + 1; }

int main() {
    push_back(10);
    push_front(20);
    printf("Front: %d, Back: %d\n", get_front(), get_back());
    return 0;
}
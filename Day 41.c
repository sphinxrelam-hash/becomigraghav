#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }
    struct Node* temp = front;
    printf("%d\n", temp->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

int main() {
    enqueue(10);
    enqueue(20);
    dequeue();
    dequeue();
    dequeue(); // Attempting to dequeue empty queue
    return 0;
}
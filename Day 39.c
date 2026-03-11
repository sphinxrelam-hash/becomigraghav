#include <stdio.h>

int heap[100];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

// Insert element and heapify up
void insert(int value) {
    heap[size] = value;
    int current = size++;
    while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

// Extract minimum and heapify down
int extractMin() {
    if (size == 0) return -1;
    int min = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    while (2 * i + 1 < size) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = left;
        if (right < size && heap[right] < heap[left]) smallest = right;
        if (heap[i] <= heap[smallest]) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return min;
}

int peek() { return size == 0 ? -1 : heap[0]; }

int main() {
    insert(40); insert(10); insert(30);
    printf("%d\n", peek());
    printf("%d\n", extractMin());
    return 0;
}
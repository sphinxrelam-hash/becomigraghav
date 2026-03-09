#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100005

// Global array and size to manage our Priority Queue
int heap[MAX_SIZE];
int size = 0;

// Helper function to swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 1. Insert an element into the Priority Queue
void insert(int val) {
    heap[size] = val; // Place at the end
    int current = size;
    size++;
    
    // Bubble Up: Compare with parent and swap if smaller
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap[current] < heap[parent]) {
            swap(&heap[current], &heap[parent]);
            current = parent;
        } else {
            break; // It is in the correct priority spot
        }
    }
}

// 2. Peek at the highest priority element
int peek() {
    if (size == 0) return -1;
    return heap[0];
}

// 3. Delete and return the highest priority element
int deleteMin() {
    if (size == 0) return -1;
    
    int minVal = heap[0];
    
    // Move the last element to the root
    heap[0] = heap[size - 1];
    size--;
    
    // Bubble Down: Restore the Min-Heap property
    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int smallest = current;
        
        // Find the smallest among parent, left child, and right child
        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        
        // If the parent is no longer the smallest, swap and continue
        if (smallest != current) {
            swap(&heap[current], &heap[smallest]);
            current = smallest;
        } else {
            break; // The heap is stable
        }
    }
    
    return minVal;
}

int main() {
    int n;
    
    // Read the number of operations
    if (scanf("%d", &n) != 1) return 0;
    
    char operation[15];
    for (int i = 0; i < n; i++) {
        scanf("%s", operation);
        
        if (strcmp(operation, "insert") == 0) {
            int val;
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(operation, "delete") == 0) {
            printf("%d\n", deleteMin());
        } else if (strcmp(operation, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    
    return 0;
}
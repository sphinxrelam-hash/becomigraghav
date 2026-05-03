#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start, end;
};

// Min-Heap array and size
int heap[1000];
int heapSize = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert an end time into the Min-Heap
void insertHeap(int val) {
    heap[heapSize] = val;
    int current = heapSize++;
    
    // Heapify up
    while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

// Get the earliest end time (root of the Min-Heap)
int getMin() {
    return (heapSize > 0) ? heap[0] : -1;
}

// Remove the earliest end time from the Min-Heap
void extractMin() {
    if (heapSize == 0) return;
    
    heap[0] = heap[--heapSize];
    int i = 0;
    
    // Heapify down
    while (2 * i + 1 < heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;
        
        if (right < heapSize && heap[right] < heap[left]) {
            smallest = right;
        }
        if (heap[i] <= heap[smallest]) break;
        
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

// Qsort comparison function to sort intervals by start time
int compareIntervals(const void *a, const void *b) {
    return ((struct Interval *)a)->start - ((struct Interval *)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    struct Interval arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // 1. Sort meetings by their start time
    qsort(arr, n, sizeof(struct Interval), compareIntervals);

    // 2. Add the end time of the first meeting to the heap
    insertHeap(arr[0].end);

    // 3. Iterate through the remaining meetings
    for (int i = 1; i < n; i++) {
        // If the earliest ending meeting is over before the current one starts,
        // we can reuse that room. Extract it from the heap.
        if (arr[i].start >= getMin()) {
            extractMin();
        }
        
        // Allocate a room for the current meeting (add its end time)
        insertHeap(arr[i].end);
    }

    // The number of active end times in the heap is the minimum rooms required
    printf("%d\n", heapSize);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    // 1. Read size
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    // Allocate the circular queue array dynamically
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0;
    int rear = -1;

    // 2. Enqueue 'n' elements
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        
        // Wrap rear around using modulo, then insert
        rear = (rear + 1) % n;
        queue[rear] = val;
    }

    // 3. Read the number of dequeue operations ('m')
    int m;
    if (scanf("%d", &m) == 1) {
        // Dequeue simply means moving the front pointer forward!
        // We use modulo just in case m > n.
        front = (front + m) % n;
    }

    // 4. Print the physical circular array starting from the new 'front'
    // This perfectly matches the requested output format (30 40 50 10 20)
    for (int i = 0; i < n; i++) {
        int index = (front + i) % n;
        printf("%d ", queue[index]);
    }
    printf("\n");

    // 5. Clean up memory
    free(queue);

    return 0;
}
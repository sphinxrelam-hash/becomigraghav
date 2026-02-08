#include <stdio.h>

int main() {
    int n;
    
    // 1. Read the size of the array
    if (scanf("%d", &n) != 1) return 0; // fast fail if input is bad

    int arr[n]; // Variable Length Array (C99 standard)

    // 2. Read the elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. The Two-Pointer Reversal Logic
    // We use two variables: 'start' at 0, 'end' at n-1
    int start = 0;
    int end = n - 1;
    int temp;

    while (start < end) {
        // Swap the elements at start and end
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move pointers towards the center
        start++;
        end--;
    }

    // 4. Print the reversed array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
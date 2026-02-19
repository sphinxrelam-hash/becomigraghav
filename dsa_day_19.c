#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort (Ascending order)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    
    // 1. Read size
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    
    // 2. Read elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Sort the array: O(N log N)
    qsort(arr, n, sizeof(int), compare);

    // 4. Two-Pointer Technique
    int left = 0;
    int right = n - 1;
    
    // Initialize with the first possible pair
    int min_sum = arr[left] + arr[right];
    int num1 = arr[left], num2 = arr[right];

    while (left < right) {
        int current_sum = arr[left] + arr[right];

        // Update if the current absolute sum is closer to zero
        if (abs(current_sum) < abs(min_sum)) {
            min_sum = current_sum;
            num1 = arr[left];
            num2 = arr[right];
        }

        // Move pointers to approach zero
        if (current_sum < 0) {
            left++;  // Need a larger value
        } else if (current_sum > 0) {
            right--; // Need a smaller value
        } else {
            break;   // Exactly zero! Can't get any closer.
        }
    }

    // 5. Print the result
    printf("%d %d", num1, num2);

    return 0;
}
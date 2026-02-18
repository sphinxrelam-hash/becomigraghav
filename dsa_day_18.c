#include <stdio.h>

// Helper function to reverse a part of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;

    // 1. Read size
    if (scanf("%d", &n) != 1) return 0;

    int arr[n]; // Variable Length Array

    // 2. Read elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Read k
    scanf("%d", &k);

    // Optimize k: if k > n, we only need to rotate k % n times
    k = k % n;

    // 4. The Three Reversals
    if (k > 0) {
        reverse(arr, 0, n - 1);    // Reverse All
        reverse(arr, 0, k - 1);    // Reverse First k
        reverse(arr, k, n - 1);    // Reverse Rest
    }

    // 5. Print the result
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
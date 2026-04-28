#include <stdio.h>

// Iterative Binary Search function
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Target found
        if (arr[mid] == target) return mid;

        // Target is in the right half
        if (arr[mid] < target) left = mid + 1;
        // Target is in the left half
        else right = mid - 1;
    }

    return -1; // Target not found
}

int main() {
    int n, target;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Array must be sorted beforehand
    }

    scanf("%d", &target);

    int result = binarySearch(arr, n, target);
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not Found\n");
    }

    return 0;
}
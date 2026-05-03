#include <stdio.h>

void countingSort(int arr[], int n) {
    if (n <= 0) return;

    // Find the maximum element to set count array size
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    int count[max + 1];
    int output[n];

    for (int i = 0; i <= max; i++) count[i] = 0;

    // Store count of each element
    for (int i = 0; i < n; i++) count[arr[i]]++;

    // Modify count array to store cumulative counts
    for (int i = 1; i <= max; i++) count[i] += count[i - 1];

    // Build the output array (backward to maintain stability)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy to original array
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    countingSort(arr, n);

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
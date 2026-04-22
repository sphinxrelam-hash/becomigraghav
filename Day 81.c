#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    // Loop through all elements
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already in place, so loop up to n-i-1
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the current element is greater than the next
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    
    // Read number of elements
    scanf("%d", &n);
    
    int arr[n];
    
    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    bubbleSort(arr, n);
    
    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
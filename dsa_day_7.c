#include <stdio.h>

int main() {
    int n;
    
    // 1. Read size
    if (scanf("%d", &n) != 1 || n <= 0) return 0; // Handle empty input safely

    int arr[n]; // Variable Length Array

    // 2. Read sorted elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Remove Duplicates Logic
    // 'k' tracks the index of the LAST unique element found
    int k = 0; 

    for (int i = 1; i < n; i++) {
        
        // Compare current number (i) with the last unique number (k)
        // If they are different, we found a new unique number!
        if (arr[i] != arr[k]) {
            k++;            // Move Keeper forward
            arr[k] = arr[i]; // Store the new unique number
        }
    }

    // 4. Print Unique Elements
    // We print up to index 'k' (inclusive)
    for (int i = 0; i <= k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
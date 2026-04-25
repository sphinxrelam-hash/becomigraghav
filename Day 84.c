#include <stdio.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    // Loop starting from the second element
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // The element to be placed correctly
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // Place the key in its correct location
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    insertionSort(arr, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
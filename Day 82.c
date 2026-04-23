#include <stdio.h>

// Finds the first index where arr[index] >= x
int lowerBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n; // Default to n if all elements are smaller than x
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] >= x) {
            ans = mid;       // Potential answer found
            right = mid - 1; // Look for a smaller index on the left
        } else {
            left = mid + 1;  // Look on the right
        }
    }
    return ans;
}

// Finds the first index where arr[index] > x
int upperBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n; // Default to n if no element is strictly greater
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] > x) {
            ans = mid;       // Potential answer found
            right = mid - 1; // Look for a smaller index on the left
        } else {
            left = mid + 1;  // Look on the right
        }
    }
    return ans;
}

int main() {
    int n, x;
    
    // Read number of elements
    scanf("%d", &n);
    
    int arr[n];
    
    // Read the sorted array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read target value
    scanf("%d", &x);
    
    // Print lower and upper bound indices
    printf("%d %d\n", lowerBound(arr, n, x), upperBound(arr, n, x));
    
    return 0;
}
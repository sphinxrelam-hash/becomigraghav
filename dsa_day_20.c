#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int count = 0;
    
    // Check all possible subarrays starting at index i
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        
        // Expand the subarray to the right
        for (int j = i; j < n; j++) {
            current_sum += arr[j]; 
            
            // If the running sum hits zero, we found a valid subarray
            if (current_sum == 0) {
                count++;
            }
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}
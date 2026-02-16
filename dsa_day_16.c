#include <stdio.h>

int main() {
    int n;
    
    // 1. Read size
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    int visited[n]; // To mark processed elements
    
    // 2. Read elements and initialize visited array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; // 0 means not visited
    }

    // 3. Count frequencies
    for (int i = 0; i < n; i++) {
        
        // Skip if this element is already counted
        if (visited[i] == 1) continue;
        
        int count = 1;
        
        // Check remaining elements for duplicates
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = 1; // Mark duplicate as visited
                count++;
            }
        }
        
        printf("%d:%d ", arr[i], count);
    }

    return 0;
}
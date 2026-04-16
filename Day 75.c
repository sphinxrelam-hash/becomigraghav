#include <stdio.h>

int main() {
    int n = 0;
    int arr[1000]; // Assuming max 1000 elements for beginner array
    
    // Read array until EOF (or handle specific length if required)
    // Here we read dynamically since input format didn't specify array length N
    while(scanf("%d", &arr[n]) == 1) {
        n++;
    }

    int max_len = 0;

    // Simple nested loop approach (O(n^2))
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            
            // If sum is zero, check if it's the longest we've seen
            if (current_sum == 0) {
                if (j - i + 1 > max_len) {
                    max_len = j - i + 1;
                }
            }
        }
    }

    printf("%d\n", max_len);
    return 0;
}
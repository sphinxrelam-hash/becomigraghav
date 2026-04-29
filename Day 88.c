#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if placing cows with 'minDist' is possible
int canPlaceCows(int stalls[], int n, int k, int minDist) {
    int cowsPlaced = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= minDist) {
            cowsPlaced++;
            lastPos = stalls[i];
            if (cowsPlaced == k) return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Sort the stalls first
    qsort(stalls, n, sizeof(int), compare);

    int left = 1; // Minimum possible distance
    int right = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int bestDist = 0;

    // Binary search on the answer
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            bestDist = mid;   // 'mid' is possible, try for a larger distance
            left = mid + 1;
        } else {
            right = mid - 1;  // 'mid' is not possible, try a smaller distance
        }
    }

    printf("%d\n", bestDist);
    return 0;
}
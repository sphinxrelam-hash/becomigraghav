#include <stdio.h>
#include <stdlib.h>

int main() {
    int p, q;

    // --- Input Server 1 Log ---
    scanf("%d", &p);
    // Allocate memory dynamically for Log 1
    int *log1 = (int*)malloc(p * sizeof(int));
    for (int k = 0; k < p; k++) {
        scanf("%d", &log1[k]);
    }

    // --- Input Server 2 Log ---
    scanf("%d", &q);
    // Allocate memory dynamically for Log 2
    int *log2 = (int*)malloc(q * sizeof(int));
    for (int k = 0; k < q; k++) {
        scanf("%d", &log2[k]);
    }

    // --- The Merging Logic ---
    int i = 0, j = 0;

    // Compare elements while both logs have data
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++; // Move Server 1 pointer
        } else {
            printf("%d ", log2[j]);
            j++; // Move Server 2 pointer
        }
    }

    // Print remaining elements from Server 1 (if any)
    while (i < p) {
        printf("%d ", log1[i++]);
    }

    // Print remaining elements from Server 2 (if any)
    while (j < q) {
        printf("%d ", log2[j++]);
    }

    // Free the allocated memory (Good Practice!)
    free(log1);
    free(log2);

    return 0;
}
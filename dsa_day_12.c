#include <stdio.h>

int main() {
    int m, n;

    // 1. Read Dimensions
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // 2. The Gatekeeper: Check if it is a Square Matrix
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0; // Stop the program here!
    }

    // 3. Read the Matrix
    int matrix[m][n]; // Variable Length Array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 4. Check for Symmetry
    int isSymmetric = 1; // Assume it IS symmetric (True) initially

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            
            // Compare element at [i][j] with element at [j][i]
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; // False! We found a mismatch.
                break; // No need to check further
            }
        }
        if (isSymmetric == 0) break; // Break outer loop too
    }

    // 5. Print the verdict
    if (isSymmetric) {
        printf("Symmetric Matrix");
    } else {
        printf("Not a Symmetric Matrix");
    }

    return 0;
}
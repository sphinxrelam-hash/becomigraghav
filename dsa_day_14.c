#include <stdio.h>

int main() {
    int n;

    // 1. Read size (Square Matrix)
    if (scanf("%d", &n) != 1) return 0;

    // 2. Variable Length Array (VLA)
    int matrix[n][n];

    // 3. Read the Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 4. The Identity Check
    int isIdentity = 1; // Assume True initially

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            // Case A: Main Diagonal (i == j)
            if (i == j) {
                if (matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } 
            // Case B: Non-Diagonal (i != j)
            else {
                if (matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if (isIdentity == 0) break; // Break outer loop if failed
    }

    // 5. Print Result
    if (isIdentity) {
        printf("Identity Matrix");
    } else {
        printf("Not an Identity Matrix");
    }

    return 0;
}
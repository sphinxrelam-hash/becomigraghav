#include <stdio.h>

int main() {
    int m, n;

    // 1. Read Dimensions
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // 2. Declare Matrix (VLA)
    int matrix[m][n];

    // 3. Read the Matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 4. Calculate Diagonal Sum
    long long sum = 0; // Use long long to prevent overflow
    
    // Determine the length of the diagonal
    // The diagonal length is limited by the smaller dimension
    int min_dim = (m < n) ? m : n;

    // SINGLE LOOP: O(min(m, n)) instead of O(m * n)
    for (int i = 0; i < min_dim; i++) {
        sum += matrix[i][i]; // Add element at [0][0], [1][1], etc.
    }

    // 5. Print the result
    printf("%lld", sum);

    return 0;
}
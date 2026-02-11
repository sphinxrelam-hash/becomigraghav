#include <stdio.h>

int main() {
    int m, n;

    // 1. Read the dimensions
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // 2. Declare matrices with exact size needed (C99 Standard)
    int a[m][n];
    int b[m][n];
    int sum[m][n];

    // 3. Input Matrix A
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // 4. Input Matrix B
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // 5. Calculate Sum and Print
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            
            // The logic: Add element from A to element from B at same position
            sum[i][j] = a[i][j] + b[i][j];
            
            printf("%d ", sum[i][j]);
        }
        // Move to the next line after printing one row
        printf("\n");
    }

    return 0;
}
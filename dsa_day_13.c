#include <stdio.h>

int main() {
    int r, c;

    // 1. Read Dimensions
    if (scanf("%d %d", &r, &c) != 2) return 0;

    // 2. Declare Matrix (VLA)
    int matrix[r][c];

    // 3. Input Matrix Elements
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 4. Initialize Boundaries
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    // 5. Spiral Traversal
    while (top <= bottom && left <= right) {
        
        // Traverse Right (Top Row)
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++; // Top wall moves down

        // Traverse Down (Right Column)
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--; // Right wall moves left

        // Traverse Left (Bottom Row)
        // Check if rows remain to avoid re-printing the same row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--; // Bottom wall moves up
        }

        // Traverse Up (Left Column)
        // Check if cols remain to avoid re-printing the same column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++; // Left wall moves right
        }
    }

    return 0;
}
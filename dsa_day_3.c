#include <stdio.h>

int main() {
    int n, k, i, c = 0;

    scanf("%d", &n);
    int a[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        c++;
        if (a[i] == k) {
            printf("Found at index %d\nComparisons = %d\n", i, c);
            return 0;
        }
    }

    printf("Not Found\nComparisons = %d\n", c);
    return 0;
}
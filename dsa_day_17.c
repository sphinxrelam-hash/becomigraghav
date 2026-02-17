#include <stdio.h>

int main() {
    int n;

    // 1. Read size
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // 2. Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Initialize max and min with the first element
    int max = arr[0];
    int min = arr[0];

    // 4. Traverse the array to update max and min
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // 5. Print the result
    printf("Max: %d\n", max);
    printf("Min: %d", min);

    return 0;
}
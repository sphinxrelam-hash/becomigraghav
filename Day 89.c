#include <stdio.h>

// Function to check if 'maxPages' is a valid allocation
int isValid(int arr[], int n, int m, int maxPages) {
    int studentsRequired = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        // A single book has more pages than 'maxPages', allocation impossible
        if (arr[i] > maxPages) return 0;

        if (currentSum + arr[i] > maxPages) {
            studentsRequired++;
            currentSum = arr[i];
            if (studentsRequired > m) return 0;
        } else {
            currentSum += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > max) max = arr[i];
    }

    // Edge case: more students than books
    if (m > n) {
        printf("-1\n");
        return 0;
    }

    int left = max, right = sum, ans = -1;

    // Binary search on the maximum pages allocated
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isValid(arr, n, m, mid)) {
            ans = mid;       // Valid allocation, try to minimize further
            right = mid - 1;
        } else {
            left = mid + 1;  // Not valid, we need a higher limit
        }
    }

    printf("%d\n", ans);
    return 0;
}
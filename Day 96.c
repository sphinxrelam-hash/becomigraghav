#include <stdio.h>

long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long inv_count = 0;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // arr[i] > arr[j], so elements from i to mid-1 are all > arr[j]
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) arr[i] = temp[i];

    return inv_count;
}

long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], temp[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    long long inversions = mergeSortAndCount(arr, temp, 0, n - 1);
    printf("%lld\n", inversions);

    return 0;
}
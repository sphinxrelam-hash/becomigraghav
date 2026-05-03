#include <stdio.h>
#include <stdlib.h>

struct Element {
    int value, originalIndex;
};

// Merge function that updates the count of smaller elements on the right
void merge(struct Element arr[], int left, int mid, int right, int result[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    struct Element L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int rightCounter = 0; // Tracks elements placed from the right array

    while (i < n1 && j < n2) {
        // Since we want smaller on right, we place the smaller element first
        if (R[j].value < L[i].value) {
            rightCounter++;
            arr[k++] = R[j++];
        } else {
            // L[i] is greater/equal, so we update its count
            result[L[i].originalIndex] += rightCounter;
            arr[k++] = L[i++];
        }
    }

    // Add remaining elements of L
    while (i < n1) {
        result[L[i].originalIndex] += rightCounter;
        arr[k++] = L[i++];
    }

    // Add remaining elements of R
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(struct Element arr[], int left, int right, int result[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, result);
        mergeSort(arr, mid + 1, right, result);
        merge(arr, left, mid, right, result);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Element arr[n];
    int result[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].originalIndex = i;
        result[i] = 0; // Initialize result counts to zero
    }

    mergeSort(arr, 0, n - 1, result);

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
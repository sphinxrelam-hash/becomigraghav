#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int isValid = 1;
    
    // Check if every parent is smaller than or equal to its children
    for (int i = 0; i <= (n / 2) - 1; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < n && arr[i] > arr[leftChild]) {
            isValid = 0;
            break;
        }
        if (rightChild < n && arr[i] > arr[rightChild]) {
            isValid = 0;
            break;
        }
    }

    if (isValid) {
        printf("YES\n"); // Print YES if valid Min-Heap 
    } else {
        printf("NO\n");
    }

    return 0;
}
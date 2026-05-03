#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start, end;
};

// Sort intervals based on starting points
int compare(const void *a, const void *b) {
    return ((struct Interval *)a)->start - ((struct Interval *)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);
    struct Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(struct Interval), compare);

    int index = 0; // Represents the size of the merged array
    for (int i = 1; i < n; i++) {
        // If overlapping, update the end of the previous interval
        if (arr[index].end >= arr[i].start) {
            if (arr[i].end > arr[index].end) {
                arr[index].end = arr[i].end;
            }
        } else {
            // Not overlapping, move to the next
            index++;
            arr[index] = arr[i];
        }
    }

    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", arr[i].start, arr[i].end);
    }
    printf("\n");

    return 0;
}
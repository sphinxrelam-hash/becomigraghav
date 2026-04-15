#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Comparison function for qsort to sort strings lexicographically
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    scanf("%d", &n);

    // Array of string pointers
    char *arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(55 * sizeof(char));
        scanf("%s", arr[i]);
    }

    // Sort the names alphabetically
    qsort(arr, n, sizeof(char *), compareStrings);

    int max_votes = 0;
    int current_votes = 1;
    char winner[55];
    strcpy(winner, arr[0]);

    // Count consecutive duplicates to find the max votes
    for (int i = 1; i < n; i++) {
        if (strcmp(arr[i], arr[i - 1]) == 0) {
            current_votes++;
        } else {
            if (current_votes > max_votes) {
                max_votes = current_votes;
                strcpy(winner, arr[i - 1]);
            }
            current_votes = 1;
        }
    }

    // Final check for the last counted sequence
    if (current_votes > max_votes) {
        max_votes = current_votes;
        strcpy(winner, arr[n - 1]);
    }

    printf("%s %d\n", winner, max_votes);

    // Free memory
    for (int i = 0; i < n; i++) free(arr[i]);

    return 0;
}
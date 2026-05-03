#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

// Insert into a sorted linked list
void insertSorted(struct Node** head_ref, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head_ref == NULL || (*head_ref)->data >= newNode->data) {
        newNode->next = *head_ref;
        *head_ref = newNode;
    } else {
        struct Node* current = *head_ref;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void bucketSort(float arr[], int n) {
    struct Node* buckets[n];
    for (int i = 0; i < n; i++) buckets[i] = NULL;

    // Distribute array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Value is in [0, 1)
        insertSorted(&buckets[bucketIndex], arr[i]);
    }

    // Concatenate all buckets back into the array
    int index = 0;
    for (int i = 0; i < n; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            struct Node* temp = current;
            current = current->next;
            free(temp); // Free memory
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++) scanf("%f", &arr[i]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) printf("%.4f ", arr[i]);
    printf("\n");
    return 0;
}
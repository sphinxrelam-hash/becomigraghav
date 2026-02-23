#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a linked list of size n
struct Node* createList(int n) {
    if (n <= 0) return NULL;
    
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to merge two sorted lists
struct Node* mergeTwoLists(struct Node* list1, struct Node* list2) {
    struct Node dummy;       // Dummy node simplifies edge cases
    dummy.next = NULL;
    struct Node* tail = &dummy; // Tail pointer to build the new list

    // 1. Compare and attach the smaller node
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next; // Move the tail forward
    }

    // 2. Attach any remaining nodes from either list
    if (list1 != NULL) tail->next = list1;
    if (list2 != NULL) tail->next = list2;

    return dummy.next; // The real head is next to the dummy
}

int main() {
    int n, m;

    // Read and create first list
    if (scanf("%d", &n) != 1) return 0;
    struct Node* list1 = createList(n);

    // Read and create second list
    if (scanf("%d", &m) != 1) return 0;
    struct Node* list2 = createList(m);

    // Merge the lists
    struct Node* mergedHead = mergeTwoLists(list1, list2);

    // Print the merged list
    struct Node* current = mergedHead;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}
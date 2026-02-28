#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a linked list
struct Node* createList(int n) {
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

// Helper function to get the length of a list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

int main() {
    int n, m;

    // 1. Read sizes and create lists
    if (scanf("%d", &n) != 1) return 0;
    struct Node* head1 = createList(n);

    if (scanf("%d", &m) != 1) return 0;
    struct Node* head2 = createList(m);

    // 2. Get lengths
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // 3. Give the longer list a head start
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            ptr1 = ptr1->next;
        }
    } else {
        for (int i = 0; i < len2 - len1; i++) {
            ptr2 = ptr2->next;
        }
    }

    // 4. Traverse together to find the intersection
    int intersection = -1;
    while (ptr1 != NULL && ptr2 != NULL) {
        // Checking data for standard IO. (Use ptr1 == ptr2 in real node-merges)
        if (ptr1->data == ptr2->data) { 
            intersection = ptr1->data;
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // 5. Print Result
    if (intersection != -1) {
        printf("%d\n", intersection);
    } else {
        printf("No Intersection\n");
    }

    return 0;
}
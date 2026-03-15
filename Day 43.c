#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    if (data == -1) return NULL; // -1 represents NULL
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (n == 0 || arr[0] == -1) return 0;

    struct Node* queue[100];
    int front = 0, rear = 0;
    
    struct Node* root = createNode(arr[0]);
    queue[rear++] = root;
    int i = 1;

    // Use queue to construct tree level by level
    while (front < rear && i < n) {
        struct Node* curr = queue[front++];
        curr->left = createNode(arr[i++]);
        if (curr->left) queue[rear++] = curr->left;
        
        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) queue[rear++] = curr->right;
        }
    }

    inorder(root);
    return 0;
}
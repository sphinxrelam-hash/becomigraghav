#include <stdio.h>

struct Node {
    int data;
    struct Node *left, *right;
};

void levelOrder(struct Node* root) {
    if (root == NULL) return;
    
    struct Node* queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        struct Node* curr = queue[front++];
        printf("%d ", curr->data);
        
        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
}

int main() {
    struct Node* root = NULL; // Replace with tree creation logic
    // levelOrder(root);
    return 0;
}
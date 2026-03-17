#include <stdio.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Recursively find maximum depth
int height(struct Node* root) {
    if (root == NULL) return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Return larger height + 1
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    struct Node* root = NULL; // Replace with tree creation logic
    // printf("%d\n", height(root));
    return 0;
}
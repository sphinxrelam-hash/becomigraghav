#include <stdio.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Count nodes where left and right are both NULL
int countLeaves(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    struct Node* root = NULL; // Replace with tree creation logic
    // printf("%d\n", countLeaves(root));
    return 0;
}
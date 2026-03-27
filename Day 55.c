#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Track the maximum level visited so far
void rightViewUtil(struct Node* root, int level, int* max_level) {
    if (root == NULL) return;

    // If this is the first node of its level, print it
    if (*max_level < level) {
        printf("%d ", root->data);
        *max_level = level;
    }

    // Recurse for right subtree first, then left subtree
    // At each level, the rightmost node is visible [cite: 43]
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

void rightView(struct Node* root) {
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
    printf("\n");
}

int main() {
    // Tree setup...
    struct Node* root = NULL; 
    // rightView(root);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Check if two trees are mirror images of each other [cite: 46]
int isMirror(struct Node* root1, struct Node* root2) {
    // If both are empty, they are symmetric
    if (root1 == NULL && root2 == NULL) return 1;

    // If both are non-empty, compare their values and subtrees
    if (root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left, root2->right) &&
               isMirror(root1->right, root2->left);

    // If one is empty and the other isn't, or values differ
    return 0;
}

int isSymmetric(struct Node* root) {
    // Check if the tree is a mirror of itself
    return isMirror(root, root);
}

int main() {
    struct Node* root = NULL; // Tree setup...
    
    if (isSymmetric(root)) printf("YES\n"); // Print YES if symmetric [cite: 45]
    else printf("NO\n");
    
    return 0;
}
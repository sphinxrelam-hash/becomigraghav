#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Assuming a pre-built tree for brevity in general BT problems
// A standard recursive function to find LCA
struct Node* findLCA(struct Node* root, int n1, int n2) {
    // Base case
    if (root == NULL) return NULL;

    // If either n1 or n2 matches root's key, report the presence
    if (root->data == n1 || root->data == n2)
        return root;

    // Look for keys in left and right subtrees
    struct Node* left_lca = findLCA(root->left, n1, n2);
    struct Node* right_lca = findLCA(root->right, n1, n2);

    // If both returned non-NULL, then one key is present in left 
    // and other is present in right. This node is the LCA.
    if (left_lca && right_lca) return root;

    // Otherwise check if left or right subtree had a match
    return (left_lca != NULL) ? left_lca : right_lca;
}

int main() {
    // Manual tree construction mapping to level-order: 1 2 3 4 5 6 7 [cite: 34]
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->data = 2;
    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->data = 3;
    // ... setup the rest of the nodes ...

    int n1 = 4, n2 = 5;
    struct Node* lca = findLCA(root, n1, n2);
    
    if (lca != NULL) printf("%d\n", lca->data);

    return 0;
}
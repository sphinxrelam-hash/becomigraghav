#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to find LCA in BST
struct Node* lcaBST(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If both n1 and n2 are smaller than root, LCA lies in left
    if (root->data > n1 && root->data > n2)
        return lcaBST(root->left, n1, n2);

    // If both n1 and n2 are greater than root, LCA lies in right
    if (root->data < n1 && root->data < n2)
        return lcaBST(root->right, n1, n2);

    // Otherwise, current node is LCA
    return root;
}

int main() {
    int n, n1, n2;
    scanf("%d", &n); // Read N [cite: 32]
    
    struct Node* root = NULL;
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val); // Read tree elements [cite: 32]
        root = insert(root, val);
    }
    
    scanf("%d %d", &n1, &n2); // Read the two nodes [cite: 32]
    
    struct Node* lca = lcaBST(root, n1, n2);
    if (lca != NULL) printf("%d\n", lca->data); // Print the LCA value [cite: 33]

    return 0;
}
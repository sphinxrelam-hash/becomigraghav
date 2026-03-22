#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new BST node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Search for a value in the BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;
    
    // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);
    
    // Key is smaller than root's key
    return search(root->left, key);
}

int main() {
    // Manual tree creation for demonstration
    struct Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);

    int target = 40;
    struct Node* result = search(root, target);

    if (result != NULL) {
        printf("Found: %d\n", result->data);
    } else {
        printf("Not Found\n");
    }

    return 0;
}
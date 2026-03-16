#include <stdio.h>

struct Node {
    int data;
    struct Node *left, *right;
};

void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Assuming tree is constructed similar to Day 43...
    struct Node* root = NULL; // Replace with tree creation logic
    // inorder(root); printf("\n");
    // preorder(root); printf("\n");
    // postorder(root); printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int height(struct Node* node) {
    if (node == NULL) return 0;
    int lheight = height(node->left);
    int rheight = height(node->right);
    return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
}

// Print nodes at a specific level based on direction flag
void printGivenLevel(struct Node* root, int level, int ltr) {
    if (root == NULL) return;
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        if (ltr) {
            printGivenLevel(root->left, level - 1, ltr);
            printGivenLevel(root->right, level - 1, ltr);
        } else {
            printGivenLevel(root->right, level - 1, ltr);
            printGivenLevel(root->left, level - 1, ltr);
        }
    }
}

void printZigZag(struct Node* root) {
    int h = height(root);
    int ltr = 1; // Left-to-right flag
    
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i, ltr);
        ltr = !ltr; // Flip the flag for alternate traversal [cite: 40]
    }
    printf("\n");
}

int main() {
    // Tree setup...
    struct Node* root = NULL; 
    // printZigZag(root);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to find minimum and maximum horizontal distances
void findMinMax(struct Node* node, int *min, int *max, int hd) {
    if (node == NULL) return;

    if (hd < *min) *min = hd;
    else if (hd > *max) *max = hd;

    findMinMax(node->left, min, max, hd - 1);
    findMinMax(node->right, min, max, hd + 1);
}

// Function to print nodes at a given horizontal distance
void printVerticalLine(struct Node* node, int line_no, int hd) {
    if (node == NULL) return;
    
    if (hd == line_no)
        printf("%d ", node->data); // Nodes sharing the same distance are printed together [cite: 37]

    printVerticalLine(node->left, line_no, hd - 1);
    printVerticalLine(node->right, line_no, hd + 1);
}

void verticalOrder(struct Node* root) {
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    for (int line_no = min; line_no <= max; line_no++) {
        printVerticalLine(root, line_no, 0);
        printf("\n");
    }
}

int main() {
    // Example setup...
    struct Node* root = NULL; // Initialize with your tree
    // verticalOrder(root);
    return 0;
}
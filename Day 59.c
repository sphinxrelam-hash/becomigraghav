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

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Postorder gives root at end, inorder divides left and right subtrees [cite: 52]
struct Node* buildTreePostIn(int in[], int post[], int inStrt, int inEnd, int* pIndex) {
    if (inStrt > inEnd) return NULL;

    // Pick current node from Postorder traversal using pIndex and decrement
    struct Node* node = createNode(post[*pIndex]);
    (*pIndex)--;

    if (inStrt == inEnd) return node;

    // Find the index of this node in Inorder traversal
    int iIndex = search(in, inStrt, inEnd, node->data);

    // Right child is built BEFORE left child because postorder evaluates from right to left
    node->right = buildTreePostIn(in, post, iIndex + 1, inEnd, pIndex);
    node->left = buildTreePostIn(in, post, inStrt, iIndex - 1, pIndex);

    return node;
}

void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data); // Print preorder traversal of constructed tree [cite: 52]
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int n = 5;
    int in[] = {4, 2, 5, 1, 3};
    int post[] = {4, 5, 2, 3, 1};
    int pIndex = n - 1; // Start from the last element
    
    struct Node* root = buildTreePostIn(in, post, 0, n - 1, &pIndex);
    printPreorder(root);
    printf("\n");
    return 0;
}
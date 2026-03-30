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

// Preorder identifies root, inorder splits left and right subtrees [cite: 50]
struct Node* buildTree(int in[], int pre[], int inStrt, int inEnd, int* preIndex) {
    if (inStrt > inEnd) return NULL;

    // Pick current node from Preorder traversal using preIndex
    struct Node* tNode = createNode(pre[*preIndex]);
    (*preIndex)++;

    if (inStrt == inEnd) return tNode;

    // Find the index of this node in Inorder traversal
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    // Construct left and right subtrees
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, preIndex);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return tNode;
}

void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data); // Print postorder traversal of constructed tree [cite: 50]
}

int main() {
    int n = 5;
    int pre[] = {1, 2, 4, 5, 3};
    int in[] = {4, 2, 5, 1, 3};
    int preIndex = 0;
    
    struct Node* root = buildTree(in, pre, 0, n - 1, &preIndex);
    printPostorder(root);
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list [cite: 58]
struct Node {
    int vertex;
    struct Node* next;
};

// Function to add an edge to the adjacency list
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m;
    // Read n (vertices) and m (edges) 
    scanf("%d %d", &n, &m);

    // Array of pointers for adjacency lists 
    struct Node* adj[n + 1];
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    // Read edges (u, v) 
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u); // Assuming undirected
    }

    // Print the adjacency list 
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}
#include <stdio.h>

int main() {
    int n, m;
    // Read vertices and edges [cite: 57]
    scanf("%d %d", &n, &m);

    // Initialize an n x n adjacency matrix with 0s
    int adj[100][100] = {0};

    // Read m pairs of edges [cite: 57]
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Assuming undirected graph for demonstration
    }

    // Print the n x n adjacency matrix [cite: 57]
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
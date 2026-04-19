#include <stdio.h>
#define INF 999999

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n + 1][n + 1];
    
    // Initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int key[n + 1];
    int mstSet[n + 1];
    
    for (int i = 1; i <= n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[1] = 0; // Start from vertex 1
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        // Pick minimum key vertex not yet in MST
        int min = INF, u = -1;
        for (int v = 1; v <= n; v++) {
            if (mstSet[v] == 0 && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        mstSet[u] = 1;
        totalWeight += key[u];

        // Update key values of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != INF && mstSet[v] == 0 && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}
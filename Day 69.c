#include <stdio.h>

#define INF 999999

int main() {
    int n, m, source;
    // Input n (vertices) and m (edges) 
    scanf("%d %d", &n, &m);

    int adj[100][100];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = INF;
        }
    }

    // Input weighted edges 
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w; // Assuming directed graph
    }

    scanf("%d", &source);

    int dist[100], visited[100] = {0};
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[source] = 0;

    // Compute shortest path 
    for (int count = 1; count <= n - 1; count++) {
        // Simple array-based priority search
        int min = INF, u = -1;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break; 
        visited[u] = 1;

        // Relax neighbors
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && adj[u][v] != INF && dist[u] != INF 
                && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    // Print shortest distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}
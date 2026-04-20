#include <stdio.h>
#define INF 999999

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w; // Assuming directed graph; for undirected, add adj[v][u]=w
    }

    int source;
    scanf("%d", &source);

    int dist[n + 1];
    int visited[n + 1];
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    
    dist[source] = 0;

    for (int count = 1; count <= n - 1; count++) {
        int min = INF, u = -1;
        
        // Find vertex with minimum distance
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        if (u == -1) break; // All remaining vertices are inaccessible
        visited[u] = 1;

        // Update distances for neighbors
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && adj[u][v] != INF && dist[u] != INF 
                && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}
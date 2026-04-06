#include <stdio.h>

int adj[100][100], visited[100], n;

// DFS function tracking the parent node 
int detectCycle(int vertex, int parent) {
    visited[vertex] = 1;

    for (int i = 1; i <= n; i++) {
        if (adj[vertex][i] == 1) {
            // If adjacent node is unvisited, recurse
            if (!visited[i]) {
                if (detectCycle(i, vertex)) return 1;
            } 
            // If adjacent node is visited and is not the parent, we found a cycle 
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int hasCycle = 0;
    // Handle disconnected components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (detectCycle(i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    // Output YES or NO 
    if (hasCycle) printf("YES\n");
    else printf("NO\n");

    return 0;
}
#include <stdio.h>

int adj[100][100], visited[100], n;

// Recursive DFS function 
void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex); // Print traversal order 

    for (int i = 1; i <= n; i++) {
        // If there's an edge and the node is unvisited, go deeper
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int m, source;
    // Input n, adjacency list (matrix used here for simplicity), and starting vertex s 
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    scanf("%d", &source);
    
    // Start DFS from the source
    dfs(source);
    printf("\n");

    return 0;
}
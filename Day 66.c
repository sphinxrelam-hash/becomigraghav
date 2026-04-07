#include <stdio.h>

int adj[100][100], visited[100], recStack[100], n;

// DFS checking the recursion stack for back edges 
int detectCycleDirected(int vertex) {
    visited[vertex] = 1;
    recStack[vertex] = 1; // Add to current path stack

    for (int i = 1; i <= n; i++) {
        if (adj[vertex][i] == 1) {
            if (!visited[i] && detectCycleDirected(i)) {
                return 1;
            } else if (recStack[i]) {
                // If it's already in the recursion stack, cycle exists 
                return 1;
            }
        }
    }
    
    // Remove from stack before returning
    recStack[vertex] = 0; 
    return 0;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Directed graph, so only one-way link
    }

    int hasCycle = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (detectCycleDirected(i)) {
                hasCycle = 1;
                break;
            }
        }
    }

    // Output YES if cycle exists 
    if (hasCycle) printf("YES\n");
    else printf("NO\n");

    return 0;
}
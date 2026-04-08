#include <stdio.h>

int adj[100][100], visited[100], n;
int stack[100], top = -1;

// Push to stack when all descendants are visited 
void dfs(int vertex) {
    visited[vertex] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = vertex;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Directed Graph
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Pop everything from the stack to get the topological order
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");

    return 0;
}
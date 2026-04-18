#include <stdio.h>

int adj[100][100];
int visited[100];
int n;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int m, u, v;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Start DFS from vertex 1
    dfs(1);

    // If any vertex is not visited, it's not connected
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected) printf("CONNECTED\n");
    else printf("NOT CONNECTED\n");

    return 0;
}
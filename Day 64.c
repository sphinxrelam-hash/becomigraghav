#include <stdio.h>

int adj[100][100], visited[100], n;
int queue[100], front = 0, rear = 0;

int main() {
    int m, source;
    // Input n, adjacency list, source s 
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    scanf("%d", &source);

    // Enqueue source and mark as visited 
    queue[rear++] = source;
    visited[source] = 1;

    // BFS loop 
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr); // BFS traversal order 

        for (int i = 1; i <= n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");

    return 0;
}
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[100][100] = {0};
    int inDegree[100] = {0}; // Track incoming edges 

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        inDegree[v]++; // Increment in-degree for destination
    }

    int queue[100], front = 0, rear = 0;

    // Enqueue all vertices with 0 in-degree 
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        count++;

        // Reduce in-degree of neighbors
        for (int i = 1; i <= n; i++) {
            if (adj[curr][i] == 1) {
                inDegree[i]--;
                // If in-degree becomes 0, add to queue
                if (inDegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }
    printf("\n");

    return 0;
}
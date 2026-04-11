#include <stdio.h>
#include <stdlib.h>

#define INF 999999

// Structure to represent a directed edge
struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Edge edges[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int source;
    scanf("%d", &source); // Assuming the source is provided

    int dist[n + 1];
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[source] = 0;

    // Relax all edges V - 1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    int hasNegativeCycle = 0;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasNegativeCycle = 1;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) printf("INF ");
            else printf("%d ", dist[i]);
        }
        printf("\n");
    }
    return 0;
}
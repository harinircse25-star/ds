#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 10
#define INFINITY 999

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int src) {
    int dist[MAX_VERTICES], visited[MAX_VERTICES], i, j, min, u;
    for (i = 0; i < n; i++) {
        dist[i] = INFINITY;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (i = 0; i < n - 1; i++) {
        min = INFINITY;
        for (j = 0; j < n; j++)
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        visited[u] = 1;
        for (j = 0; j < n; j++)
            if (!visited[j] && graph[u][j] && dist[u] != INFINITY && dist[u] + graph[u][j] < dist[j])
                dist[j] = dist[u] + graph[u][j];
    }
    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES], n, src;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix (enter %d for no direct path):\n", INFINITY);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INFINITY;
        }
    }
    printf("Enter the source vertex (starting from 0): ");
    scanf("%d", &src);
    dijkstra(graph, n, src);
    return 0;
}

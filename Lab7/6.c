#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX

void dijkstra(int graph[][5], int src, int V) {
    int dist[V], visited[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1, min = INF;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + 
graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Dijkstra distances from source %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("%d -> %d: %d\n", src, i, dist[i]);
}

void bellmanFord(int graph[][3], int V, int E, int src) {
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int j = 0; j < E; j++) {
        int u = graph[j][0];
        int v = graph[j][1];
        int weight = graph[j][2];
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Bellman-Ford distances from source %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("%d -> %d: %d\n", src, i, dist[i]);
}

int main() {
    int graph1[5][5] = {
        {0, 4, 0, 0, 0},
        {0, 0, 8, 0, 0},
        {0, 0, 0, 7, 0},
        {0, 0, 0, 0, 9},
        {0, 0, 0, 0, 0}
    };
    int graph2[8][3] = {
        {0, 1, 4}, {0, 2, 4}, {1, 2, -5}, {2, 3, 6},
        {3, 1, -3}, {1, 4, 8}, {4, 3, 1}, {4, 0, 2}
    };

    int V1 = 5, V2 = 5, E2 = 8;

    dijkstra(graph1, 0, V1);
    bellmanFord(graph2, V2, E2, 0);

    return 0;
}


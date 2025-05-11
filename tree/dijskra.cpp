#include <stdio.h>

#define INF 999

void dijkstra(int cost[5][5], int n, int start) {
    int dist[5], visited[5] = {0}, i, j, min, next;

    for (i = 0; i < n; i++) {
        dist[i] = cost[start][i];
    }

    visited[start] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                next = j;
            }
        }

        visited[next] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[next] + cost[next][j] < dist[j]) {
                dist[j] = dist[next] + cost[next][j];
            }
        }
    }

    printf("Dijkstra from %c:\n", start + 'A');
    for (i = 0; i < n; i++) {
        printf("%c -> %c : %d\n", start + 'A', i + 'A', dist[i]);
    }
}

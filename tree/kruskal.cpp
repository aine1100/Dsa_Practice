#include <stdio.h>

#define MAX 100

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int cost[5][5], int n) {
    int i, j, min, u, v, ne = 0;
    int total_cost = 0;

    for (i = 0; i < n; i++) parent[i] = i;

    printf("Kruskal's MST:\n");

    while (ne < n - 1) {
        min = 999;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min && find(i) != find(j) && cost[i][j] != 0) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        union_set(u, v);
        printf("%c - %c : %d\n", u + 'A', v + 'A', min);
        total_cost += min;
        ne++;
        cost[u][v] = cost[v][u] = 999;  // Mark edge as used
    }

    printf("Total Cost: %d\n", total_cost);
}

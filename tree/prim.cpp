#include <stdio.h>

void prim(int cost[5][5], int n) {
    int visited[5] = {0};
    int i, j, min, u = 0, v = 0, total_cost = 0;

    visited[0] = 1;

    printf("Prim's MST:\n");

    for (int ne = 1; ne < n; ne++) {
        min = 999;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min && cost[i][j] != 0) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        visited[v] = 1;
        printf("%c - %c : %d\n", u + 'A', v + 'A', min);
        total_cost += min;
    }

    printf("Total Cost: %d\n", total_cost);
}

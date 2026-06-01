#include <stdio.h>

#define MAX 100

int main() {
    int n, adj[MAX][MAX], indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topo[MAX], k = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j])
                indegree[j]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    while (front < rear) {
        int u = queue[front++];
        topo[k++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    if (k != n) {
        printf("Topological ordering not possible\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < n; i++)
            printf("%d ", topo[i]);
        printf("\n");
    }

    return 0;
}
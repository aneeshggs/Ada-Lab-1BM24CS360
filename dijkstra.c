#include <stdio.h>

#define MAX 10
#define INF 9999

int main()
{
    int n, cost[MAX][MAX];
    int dist[MAX], visited[MAX];
    int i, j, u, v, min, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    for(i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for(i = 1; i < n; i++)
    {
        min = INF;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(v = 0; v < n; v++)
        {
            if(!visited[v] &&
               dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for(i = 0; i < n; i++)
    {
        if(dist[i] == INF)
            printf("%d -> %d = INF\n", source, i);
        else
            printf("%d -> %d = %d\n", source, i, dist[i]);
    }

    return 0;
}

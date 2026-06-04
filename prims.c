#include <stdio.h>

#define INF 9999

int main()
{
    int n, i, j;
    int cost[10][10];
    int visited[10] = {0};
    int min, mincost = 0;
    int a, b, u, v, ne = 1;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while(ne < n)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        printf("%d Edge (%d -> %d) = %d\n", ne++, a, b, min);
        mincost += min;
        visited[b] = 1;
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}

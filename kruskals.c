#include <stdio.h>

#define MAX 20

int parent[MAX];

int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

int unionSet(int i, int j)
{
    if(i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int n, i, j;
    int cost[MAX][MAX];
    int mincost = 0;
    int ne = 1;
    int a, b, u, v;
    int min;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while(ne < n)
    {
        min = 9999;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(unionSet(u, v))
        {
            printf("%d Edge (%d, %d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 9999;
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}

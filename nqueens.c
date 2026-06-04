#include <stdio.h>
#include <stdlib.h>

int x[20], count = 0;

int place(int k, int i)
{
    int j;

    for(j = 1; j < k; j++)
    {
        if(x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

void nQueens(int k, int n)
{
    int i, j;

    for(i = 1; i <= n; i++)
    {
        if(place(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                count++;
                printf("\nSolution %d:\n", count);

                for(j = 1; j <= n; j++)
                {
                    int col;
                    for(col = 1; col <= n; col++)
                    {
                        if(x[j] == col)
                            printf("Q ");
                        else
                            printf(". ");
                    }
                    printf("\n");
                }
            }
            else
            {
                nQueens(k + 1, n);
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter the number of Queens: ");
    scanf("%d", &n);

    nQueens(1, n);

    if(count == 0)
        printf("\nNo solutions exist.\n");
    else
        printf("\nTotal solutions = %d\n", count);

    return 0;
}

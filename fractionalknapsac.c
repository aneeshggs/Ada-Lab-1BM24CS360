#include <stdio.h>

struct Item
{
    float weight;
    float profit;
    float ratio;
};

int main()
{
    int n, i, j;
    float capacity, totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n], temp;

    printf("Enter profit and weight of each item:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f %f", &item[i].profit, &item[i].weight);
        item[i].ratio = item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    /* Sort items by profit/weight ratio in descending order */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(item[i].ratio < item[j].ratio)
            {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(item[i].weight <= capacity)
        {
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        }
        else
        {
            totalProfit += item[i].profit * (capacity / item[i].weight);
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}

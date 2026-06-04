#include <stdio.h>
#include <time.h>

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main()
{
    int n, i, a[10000];
    clock_t start, end;
    double cpu_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integer elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();

    quicksort(a, 0, n - 1);

    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted elements are:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nTime taken = %f seconds\n", cpu_time);

    return 0;
}

void quicksort(int a[], int low, int high)
{
    int p;

    if(low < high)
    {
        p = partition(a, low, high);
        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot, i, j, temp;

    pivot = a[low];
    i = low + 1;
    j = high;

    while(1)
    {
        while(i <= high && a[i] <= pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

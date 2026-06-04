#include <stdio.h>
#include <time.h>

void heapify(int a[], int n, int i);
void heapSort(int a[], int n);

int main()
{
    int a[10000], n, i;
    clock_t start, end;
    double cpu_time;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integer elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();

    heapSort(a, n);

    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted elements are:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nTime taken = %f seconds\n", cpu_time);

    return 0;
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if(left < n && a[left] > a[largest])
        largest = left;

    if(right < n && a[right] > a[largest])
        largest = right;

    if(largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i, temp;

    /* Build Max Heap */
    for(i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    /* Extract elements one by one */
    for(i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int a[n], dir[n];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = -1;
    }

    while (1) {
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        int mobile = 0, pos = -1;

        for (int i = 0; i < n; i++) {
            int next = i + dir[i];

            if (next >= 0 && next < n && a[i] > a[next]) {
                if (a[i] > mobile) {
                    mobile = a[i];
                    pos = i;
                }
            }
        }

        if (mobile == 0)
            break;

        int swapPos = pos + dir[pos];

        int temp = a[pos];
        a[pos] = a[swapPos];
        a[swapPos] = temp;

        temp = dir[pos];
        dir[pos] = dir[swapPos];
        dir[swapPos] = temp;

        for (int i = 0; i < n; i++) {
            if (a[i] > mobile)
                dir[i] = -dir[i];
        }
    }

    return 0;
}

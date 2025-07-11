#include <stdio.h>
#include <stdlib.h>

int *rotate_right(int *a, int n, int k)
{
    int *ans = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {

        int new = (i + k) % n;
        ans[new] = a[i];
    }

    return ans;
}

int *rotate_left(int *a, int n, int k)
{
    int *ans = (int *)malloc(sizeof(int) * n);
    int m =n-1;
    int key = k-1;


    for (int i = 0; i < n; i++)
    {
        int new = (i + m - key) % n;

        ans[new] = a[i];
    }
    return ans;
}

int main()
{
    int n;
    int k;

    scanf("%d", &n);
    scanf("%d", &k);

    int input[100];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", input + i);
    }

    int *ans = rotate_right(input, n, k);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }

    int *left = rotate_left(input, n, k);

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", left[i]);
    }

    return 0;
}
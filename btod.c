#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(int *arr, int start, int end)
{
    if (end < start)
    {
        return;
    }

    for (; start < end; start++, end--)
    {
        swap(&arr[start], &arr[end]);
    }
}

int main()
{
    int n;
    int ans[32];

    scanf("%d", &n);

    int i = 0;
    int temp = n;

    while (temp)
    {
        ans[i++] = temp % 2;
        temp /= 2;
    }

    reverse(ans, 0, i - 1);

    for (int j = 0; j < i; j++)
    {
        printf("%d", ans[j]);
    }

    return 0;
}

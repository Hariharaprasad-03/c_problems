#include <stdio.h>

void get_input(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
}


void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

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

void reverse_k(int *arr, int n, int k)
{
    for (int i = 0; i < n; i += k)
    {
        int end = i + k - 1;
        if (end < n)
        {
            reverse(arr, i, end);
        }
    }
}

int main()
{
    int input[100];
    int n;
    int k;

    scanf("%d", &n);
    scanf("%d", &k);

    get_input(input, n);

    reverse_k(input, n, k);

    print(input, n);

    return 0;
}
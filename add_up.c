#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void move_zero(int *a, int n)
{
    int l = 0;

    for (int r = 0; r < n; r++)
    {
        if (a[r] > 0)
        {
            swap(&a[l], &a[r]);
            l++;
        }
    }
}

int main()
{
    int n;
    int input[100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", input + i);
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (input[i] == input[i + 1])
        {
            input[i] *= 2;
            input[i + 1] = 0;
        }
    }

    move_zero(input, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", input[i]);
    }
    printf("\n");

    return 0;
}
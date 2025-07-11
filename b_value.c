#include <stdio.h>

void solve(int a[], int *b, int len)
{

    for (int i = 0; i < len; i++)
    {
        if (*(a + i) == *b)
        {
            *b *= 2;
            solve(a, b, len);
            return;
        }
    }
}

int main()
{
    int n;
    int b;
    int input[100];

    scanf("%d", &n);
    scanf("%d", &b);
    int *ptr = &b;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", input + i);
    }

    solve(input, ptr, n);
    printf("%d", b);
    return 0;
}
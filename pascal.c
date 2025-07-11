#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int i, j;
    for (i = 0; i < n; i++)
    {
        int coef = 1;
        for (int space = 0; space <= n - i - 1; space++)
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)
        {
            if (j > 0)
                coef = coef * (i - j + 1) / j;
            printf("%4d", coef);
        }
        printf("\n");
    }
}
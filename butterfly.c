#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int start, space;

    for (int i = 1; i < 2 * n; i++)
    {
        for (int j = 1; j < 2 * n; j++)
        {
            if (i < n)
            {
                start = i;
            }
            else
            {
                start = 2 * n - i;
            }
            if (j <= start || j >= 2 * n - start)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
#include <stdio.h>

int main()
{
    int n;

    printf("enter input n : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n * 2; j++)
        {
            if (i == n - 1 || i + j == n || j - i == n)
            {
                printf("*");
            } 

            else if (j > n - i && j < n + i)
            {
                printf("+");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
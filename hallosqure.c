#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d", &a);
    int i, j;
    for (i = 1; i <= a; i++)
    {
        for (j = 1; j <= a; j++)
        {
            if (i == 1 || 1 == j || i == a || j == a)
            {
                printf("*");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}
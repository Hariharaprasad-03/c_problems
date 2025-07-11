#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int pascal[50] = {1};

    for (int i = 1; i <= n; i++)
    {

        for (int space = 0; space < n - i; space++)
        {
            printf(" ");
        }

        for (int j = 0; j < i; j++)
        {

            printf("%3d", pascal[j]);
        }
        printf("\n");
        for (int j = i; j > 0; j--)
        {
            pascal[j] = pascal[j] + pascal[j - 1];
        }
    }
    return 0;
}
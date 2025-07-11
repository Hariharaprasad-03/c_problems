#include <stdio.h>  // for printf && scanf

int main()
{

    int n;
    scanf("%d", &n);

    int temp = 0;

    for (int i = 1; i <= n; i++)
    {

        for (int space = 0; space < n - i; space++)
        {
            printf(" ");
        }

        temp += i;

        for (int j = 0, var = temp; j < i; j++, var--)
        {
            printf("%3d", var);
        }

        printf("\n");
    }
}
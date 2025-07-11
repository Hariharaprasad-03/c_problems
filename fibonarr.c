#include <stdio.h>

int main()
{

    int a[5][5];
    int i;
    int j = 0;
    int n = 20;
    int a1 = 0;
    int b1 = 1;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {

            *(*(a + i) + j) = a1;
            int temp = b1 + a1;
            a1 = b1;
            b1 = temp;
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d\t", *(*(a + i) + j));
        }
        printf("\n");
    }
}
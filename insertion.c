#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int insertoin(int a[], int len, int (*cmp)(int, int));

int decs(int a, int b)
{
    return a > b;
}

int asce(int a, int b)
{
    return a < b;
}

int main()
{
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    insertoin(a, 10, asce);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    
    printf("\n");
    insertoin(a,10,decs);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
 
    return 0;
}

int insertoin(int a[], int len, int (*cmp)(int, int))
{
    int i;
    for (i = 0; i < len; i++)
    {
        int pos = i;
        while (pos > 0 && cmp (a[pos] ,a[pos - 1]))
        {
            swap(&a[pos], &a[pos - 1]);
            pos--;
        }
    }
}
#include <stdio.h>
#include <stdbool.h>
bool compare(int a, int b)
{
    return a > b;
}

void bsort(int *a, int n)
{
    bool (*p)(int, int);
    p = &compare;

    bool swap;
    int i, j;
    for (i = 0; i < n; i++)
    {
        swap = false;
        for (j = 0; j < n - 1; j++)
        {
            if ((*p)(a[j], a[j + 1]))
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swap = true;
            }
        }
        if (!swap)
        {
            break;
        }
    }
}

int main()
{
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    bsort(a, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}
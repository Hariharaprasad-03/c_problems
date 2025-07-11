#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a[] = {0, 1, 2, 0, 0, 5, 4};

    int len = sizeof(a) / sizeof(a[0]);
    int left;
    int right = 0;

    for (int left = 0; left < len; left++)
    {
        if (a[left] > 0)
        {
            swap(&a[left], &a[right]);
            right++;
        }
    }
    
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}
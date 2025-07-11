#include <stdio.h>
#include <stdbool.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    printf("%p\n", &a[1]);
    printf("%p\n", (a + 1));
    int right = 4;
    swap(a, &a[right]);
    for (int i = 0; i < 5; i++)
    {
        printf("%d", *(a + i));
    }
}
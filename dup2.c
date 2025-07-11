#include <stdio.h>


int remove_dup(int *duplicate_array, int len)
{
    int l = 2;

    for (int r = 2; r < len; r++)
    {
        if (duplicate_array[r] != duplicate_array[l - 2])
        {
            duplicate_array[l] = duplicate_array[r];
            l++;
        }
    }
    return l;
}

int main()
{
    int input[20];
    int n;

    printf("enter number of elements\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", input + i);
    }

    int index = remove_dup(input, n);

    for (int i = 0; i < index; i++)
    {
        printf("%d", input[i]);
    }
    return 0;
}

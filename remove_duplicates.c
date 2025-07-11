
#include <stdio.h>
int remove_dup(int *duplicate_array, int arr_size)
{

    int l = 0;
    for (int r = 1; r < arr_size; r++)
    {

        if (duplicate_array[r] != duplicate_array[l])
        {
            l++;
            duplicate_array[l] = duplicate_array[r];
        }
    }
    return l + 1;
}
int main()
{
    int input[20];
    int n;

    printf("give not of elements :");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", input + i);
    }
    printf("\n");
    int index = remove_dup(input, n);

    for (int i = 0; i < index; i++)
    {
        printf("%d", input[i]);
    }
    return 0;
}
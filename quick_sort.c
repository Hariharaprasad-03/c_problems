#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] >= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

void qs(int arr[], int low, int high)
{
    if (low < high)
    {
        int part = partition(arr, low, high);
        qs(arr, low, part - 1);
        qs(arr, part + 1, high);
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    qs(arr, 0, 8);

    for (int i = 0; i < 9; i++)
    {
        printf("%d", arr[i]);
    }

    printf("\n");

    return 0;
}
#include <stdio.h>

void get_input(int *input, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", input + i);
    }
}

void freq_cnt(int *arr, int len, int *freq)
{
    for (int i = 0; i < len; i++)
    {
        freq[arr[i]]++;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high, int *freq, int (*cmp)(int, int, int[]))
{
    int pivot = freq[arr[high]];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (cmp(arr[j], arr[high], freq))
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

void qs(int *arr, int low, int high, int *freq, int (*cmp)(int, int, int[]))
{
    if (low < high)
    {
        int part = partition(arr, low, high, freq, cmp);
        
        qs(arr, low, part - 1, freq, cmp);
        qs(arr, part + 1, high, freq, cmp);
    }
}

void print_arr(int *input, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", input[i]);
    }
    printf("\n");
}

int compare(int a, int b, int *freq)
{
    if (freq[a] != freq[b])
        return freq[a] > freq[b];
    return a < b;
}

int compare2(int a, int b, int *freq)
{
    if (freq[a] != freq[b])
        return freq[a] < freq[b];
    return a < b;
}

int main()
{
    int input[100];
    int freq[1000001] = {0};
    int n;

    scanf("%d", &n);
    get_input(input, n);
    freq_cnt(input, n, freq);

    qs(input, 0, n - 1, freq, compare);

    print_arr(input, n);

    return 0;
}
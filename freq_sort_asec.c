#include <stdio.h>

void get_input(int *inputs, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", inputs + i);
    }
}

void print(int *inputs, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", inputs[i]);
    }
    printf("\n");
}

void get_freq(int *input, int n, int *freq)
{
    for (int i = 0; i < n; i++)
    {
        freq[input[i]]++;
    }
}

int compare(int a, int b, int freq[])
{
    if (freq[a] != freq[b])
    {
        return freq[a] < freq[b];
    }
    return a < b;
}
void swap(int *a, int *b)
{
    int temp = *a;
    (*a) = *b;
    *b = temp;
}

int partition(int *nums, int low, int high, int freq[], int (*compare)(int, int, int[]))
{
    int pivot = high;
    int l = low;
    for (int i = low; i < high; i++)
    {
        if (compare(nums[i], nums[pivot], freq))
        {
            swap(&nums[i], &nums[l]);
            l++;
        }
    }
    swap( &nums[l], &nums[pivot] );
    return l;
}

void qs(int *nums, int low, int high, int *freq, int (*compre)(int, int, int[]))
{
    if (low < high)
    {
        int part = partition(nums, low, high, freq, compare);
        qs(nums, low, part - 1, freq, compare);
        qs(nums, part + 1, high, freq, compare);
    }
}
int main()
{
    int n;

    scanf("%d", &n);

    int input[n];
    int freq[100001] = {0};

    get_input(input, n);
    get_freq(input, n, freq);

    qs(input, 0, n - 1, freq, compare);

    print(input, n);
    return 0;
}

// cnt freq
// set compare functions to compare freq of elements
// partition according to the fereq of elements
// sort array 
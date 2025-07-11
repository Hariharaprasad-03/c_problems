#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int count(int n)
{
    int cnt = 0;


    while (n)
    {
        cnt++;
        n /= 10;
    }
    
    return cnt;
}

int powe(int n)
{
    int p = 1;
    for (int i = 0; i < n; i++)
    {
        p *= 10;
    }
    return p;
}

void insertion_sort(int *nums, int n)
{
    int pos;

    for (int i = 0; i < n; i++)
    {
        pos = i;

        while (pos > 0 && nums[pos] < nums[pos - 1])
        {
            swap(&nums[pos], &nums[pos - 1]);
            pos--;
        }
    }
}

void solve(int index, int digits, int cur_digit, int *nums, int *marks, int *ans)
{
    if (digits == 0)
    {

        if (*ans < cur_digit)
        {
            *ans = cur_digit;
        }
    }

    if (index < 0)
    {
        return;
    }

    solve(index - 1, digits, cur_digit, nums, marks, ans);

    if (digits >= marks[index])
    {
        int power = powe(marks[index]);

        solve(index - 1, digits - marks[index], cur_digit * power + nums[index], nums, marks, ans);
    }
}

int main()
{
    int input[10];
    int n;
    int k;

    scanf("%d", &n);
    scanf("%d", &k);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", input + i);
    }

    int ans = 0;

    int mark[10] = {0};

    insertion_sort(input, n);

    for (int i = 0; i < n; i++)
    {

        mark[i] = count(input[i]);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d-", input[i]);
    //     printf("%d \n", mark[i]);
    // }

    // printf("\n");

    solve(n - 1, k, 0, input, mark, &ans);

    printf("%d", ans);

    return 0;
}
#include <stdio.h>

int max_ones(int *nums, int n, int *max_ans)
{
    int max_len = 1;
    int l = 0;

    int cur_num = nums[l];

    for (int r = 0; r < n; r++)
    {
        if (nums[r] != cur_num)
        {
            cur_num = nums[r];
            l = r;
        }

        if (r - l + 1 > max_len)
        {
            max_len = r - l + 1;
            *max_ans = nums[r];
        }
    }
    return max_len;
}

int main()
{

    int n;
    int input[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", input + i);
    }

    int max_ans = -1;
    int max_len = max_ones(input, n, &max_ans);

    printf("%d , %d \n", max_ans, max_len);
    return 0;
}
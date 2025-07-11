#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int dp[1 << 15];

int canPartition(int *nums, int n, int mask, int cur_sum, int target, int k)
{
    if (k == 0)
        return 1;

    if (dp[mask] != -1)
        return dp[mask];

    dp[mask] = 0;

    for (int i = 0; i < n; i++)
    {
        if (!(mask & (1 << i)))
        {
            if (nums[i] + cur_sum <= target)
            {
                int new_mask = mask | (1 << i);
                int new_sum = cur_sum + nums[i];

                if (canPartition(nums, n, new_mask,
                                 (new_sum == target) ? 0 : new_sum,
                                 target,
                                 (new_sum == target) ? k - 1 : k))
                {
                    return dp[mask] = 1;
                }
            }
        }
    }

    return dp[mask];
}

int can_make(int *nums, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];

    if (sum % 4 != 0)
        return 0;

    int target = sum / 4;

    qsort(nums, n, sizeof(int), cmp);
    if (nums[0] > target)
        return 0;

    memset(dp, -1, sizeof(dp));

    return canPartition(nums, n, 0, 0, target, 4);
}

int main()
{
    int input[20];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &input[i]);

    printf("%d\n", can_make(input, n));
    return 0;
}

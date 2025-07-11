#include <stdio.h>

void solve(int *nums, int index, int target, int *ans, int len)
{

    if (target == 0)
    {
        *ans += 1;
        return;
    }

    if (index >= len)
    {
        return;
    }

    solve(nums, index + 1, target, ans, len);

    if (nums[index] <= target)
    {
        solve(nums, index, target - nums[index], ans, len);
    }
    
}

int main()
{
    int n;
    int nums[100];
    int target;

    scanf("%d", &n);
    scanf("%d", &target);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", nums + i);
    }

    int ans = 0;
    int *answer = &ans;                // passing pointer

    solve(nums, 0, target, answer, n);

    printf("ans = %d", ans);
    return 0;
}
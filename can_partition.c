#include <stdio.h>
#include <stdlib.h>

int solve(int *nums, int n, int *sides, int k, int target, int ind)
{
    if (ind == n)                   // base condition
    {
        for (int i = 0; i < k; i++)
        {
            if (sides[i] != target)
            {
                return 0;
            }
        }
        return 1;
    }

    for (int i = 0; i < k; i++)
    {
        if (sides[i] + nums[ind] <= target)
        {
            sides[i] += nums[ind];

            if (solve(nums, n, sides, k, target, ind + 1))
            {
                return 1;
            }
            sides[i] -= nums[ind];            // backtrack
        }
        if (sides[i] == 0)
        {
            break;
        }
    }
    return 0;
}

int can_make(int *nums, int n)
{
    int sum = 0;
    int k = 4;              // for four sides of square

    for (int i = 0; i < n; i++)
    {
        sum += *(nums + i);
    }

    if (sum % k != 0)
    {
        return 0;
    }

    int target = sum / k;

    int *sides = (int *)calloc(4, sizeof(int));

    int res=solve(nums, n, sides, k, target, 0);
    
    free(sides);
    return res;
}

int main()
{
    int input[20];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", input + i);
    }

    int ans = can_make(input, n);

    printf("%d", ans);

    return 0;
}

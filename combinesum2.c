#include <stdio.h>
#include <stdlib.h>

void solve(int *nums, int len, int index, int target, int **result, int *returnsize, int **columnsizes,
           int *current, int currentSize)
{

    if (target == 0)

    {
        result[*returnsize] = (int *)malloc(sizeof(int) * currentSize);
        for (int i = 0; i < currentSize; i++)
        {
            result[*returnsize][i] = current[i];
        }
        (*columnsizes)[*returnsize] = currentSize;
        (*returnsize) += 1;
        return;
    }

    if (index == len)
    {
        return;
    }

    solve(nums, len, index + 1, target, result, returnsize, columnsizes, current, currentSize);

    if (nums[index] <= target)
    {
        current[currentSize] = nums[index];
        solve(nums, len, index, target - nums[index], result, returnsize, columnsizes, current, currentSize + 1);
    }
}
int **combine_sum(int *nums, int numsSizes, int target, int *returnSize, int **columnsizes)
{

    int **result = (int **)malloc(sizeof(int *) * 100);
    *columnsizes = (int *)malloc(sizeof(int) * 100);
    int current[100];
    solve(nums, numsSizes, 0, target, result, returnSize, columnsizes, current, 0);
    return result;
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

    int *columnsizes;
    int returnsizes = 0;

    int **result = combine_sum(nums, n, target, &returnsizes, &columnsizes);

    printf("combinations\n");
    for (int i = 0; i < returnsizes; i++)
    {

        for (int j = 0; j < columnsizes[i]; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
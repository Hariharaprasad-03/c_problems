#include <stdio.h>
#include <string.h>

int main()
{
    int a[10];
    int n;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int k = 3;

    int hash[10001];
        memset(hash, 0, sizeof(hash));
    int offset = 5000;

    hash[0 + offset] = 1;
    int sum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        int target = sum - k;

        if (target + offset >= 0 && target + offset < 10001 && hash[target + offset] > 0)
        {
            ans += hash[target + offset];
        }

        if (sum + offset >= 0 && sum + offset < 10001)
        {
            hash[sum + offset] += 1;
        }
    }

    printf("Number of subarrays with sum %d: %d\n", k, ans);
    return 0;
}
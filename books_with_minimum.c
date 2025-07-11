#include <stdio.h>
#include <string.h>

#define MAX 100

int min(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

int dp[MAX][MAX][20];

int solve(int l, int r, int *cost, int k, int pair_cost)
{
    if (l > r)
    {
        return 0;
    }

    if (l == r)
    {
        return cost[l];
    }

    if (dp[l][r][k] != -1)
    {
        return dp[l][r][k];
    }

    int left = cost[l] + solve(l + 1, r, cost, k, pair_cost);

    int right = cost[r] + solve(l, r - 1, cost, k, pair_cost);

    int pair = 1e9;

    if (k > 0 && l < r)
    {
        pair = pair_cost + solve(l + 1, r - 1, cost, k - 1, pair_cost);
    }

    return dp[l][r][k] = min(left, right, pair);
}

int main()
{
    int cost[100];
    int n,k;
    int pair_cost;
    

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", cost + i);
    }

    printf("enter  pair cost value : ");
    scanf(" %d", &pair_cost);

    printf("enter k value : ");
    scanf(" %d", &k);

    
    memset(dp, -1, sizeof(dp));

    // required dp size dp[n][n][k+1] : ----> 0 to k  

    int ans = solve(0, n - 1, cost, k, pair_cost);

    printf("\n ans = %d ", ans);

    return 0;
}
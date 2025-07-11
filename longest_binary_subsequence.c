#include <stdio.h>
#include <stdlib.h>

int len(char *s)
{
    int i = 0;

    while (s[i])
    {
        i++;
    }
    return i;
}

int decimal(char *b, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int pow = 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == '1')
        {
            ans += pow;
        }
        pow *= 2;
    }
    return ans;
}

void solve(int ind, char *s, int n, int k, char *cur, int cur_len, int *max_len)
{

    int val = decimal(cur, cur_len);
    if (val <= k && cur_len > *max_len)
    {
        *max_len = cur_len;
    }

    if (ind < 0)
    {
        return;
    }

    solve(ind - 1, s, n, k, cur, cur_len, max_len);

    cur[cur_len] = s[ind];
    solve(ind - 1, s, n, k, cur, cur_len + 1, max_len);
}

int longest(char *s, int n, int k)
{
    char *cur = (char *)malloc(n);
    int max_len = 0;

    solve(n - 1, s, n, k, cur, 0, &max_len);

    return max_len;
}

int main()
{
    char input[100];
    int k;

    scanf("%s", input);
    scanf("%d", &k);

    int ans = longest(input, len(input), k);

    printf("ans = %d", ans);
    return 0;
}
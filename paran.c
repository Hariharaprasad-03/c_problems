#include <stdio.h>
#include <stdlib.h>

void solve(char *ans, int cur_len, int open, int close)
{
    if (open == 0 & close == 0)
    {
        printf("%s\n", ans);
        
    }

    if (open != 0)
    {
        ans[cur_len] = '(';
        solve(ans, cur_len + 1, open - 1, close);
    }
    if (close != 0 && close > open)
    {
        ans[cur_len] = ')';
        solve(ans, cur_len + 1, open, close - 1);
    }
}

int main()
{
    int n;
    char ans[25];

    scanf("%d", &n);

    solve(ans, 0, n, n);

    return 0;
}
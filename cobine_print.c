#include <stdio.h>
#include <stdlib.h>

void solve(int ind, int *a, int len, int *cur, int cur_len, int check)
{
    if (ind >= len)
    {
        for (int i = 0; i < cur_len; i++)
        {
            printf("%c", cur[i] + 64);
        }
        printf("\n");
        return;
    }

    cur[cur_len] = a[ind];

    solve(ind + 1, a, len, cur, cur_len + 1, 0);

    if (!(check) && ind + 1 < len && a[ind] * 10 + a[ind + 1] <= 26)
    {
        cur[cur_len] = a[ind] * 10 + a[ind + 1];

        solve(ind + 2, a, len, cur, cur_len + 1, 1);
    }
}

int main()
{
    int input[10];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", input + i);
    }

    int *cur = (int *)malloc(sizeof(int) * n);
    solve(0, input, n, cur, 0, 0);

    return 0;
}
#include <stdio.h>

int str_len(char *s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

int solve(char *s, int len, int k, int cur_len, int i)
{
    // Base case
    if (i >= len)
    {
        return (cur_len >= k) ? 1 : 0;
    }

    int include = solve(s, len, k, cur_len + 1, i + 1);
    int exclude = 0;

    if (i + 1 < len && s[i] == s[i + 1])
    {
        exclude = solve(s, len, k, cur_len, i + 1);
    }

    return include + exclude;
}

int main()
{
    char input[100];
    int k;

    scanf("%s", input);
    scanf("%d", &k);

    int n = str_len(input);

    int ans = solve(input, n, k, 0, 0);

    printf("\n%d\n", ans);
    return 0;
}

#include <stdio.h>
#include <string.h>

int solve(char *s1, char *s2, char *s3, int len1, int len2, int i, int j, int dp[][len2 + 1]);

int str_len(char *s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

//inter leveling 2 strings
int main()
{
    char s1[100];
    char s2[100];
    char s3[100];

    scanf(" %s" , s1 );
    scanf(" %s" , s2 );
    scanf(" %s" , s3 );

    int len1 = str_len(s1);
    int len2 = str_len(s2);
    int len3 = str_len(s3);

    int ans;
    int dp[len1 + 1][len2 + 1];

    if (len1 + len2 != len3)
    {
        ans = 0;
    }

    else
    {

        memset(dp, -1, sizeof(dp));

        ans = solve(s1, s2, s3, len1, len2, 0, 0, dp);
    }

    printf("%d", ans);

    return 0;
}

 int solve(char *s1, char *s2, char *s3, int len1, int len2, int i, int j, int dp[][len2 + 1])
{
    if (i == len1 && j == len2)
    {
        return dp[i][j] = 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (i < len1 && s1[i] == s3[i + j])
    {
        if (solve(s1, s2, s3, len1, len2, i + 1, j, dp))
        {
            return dp[i][j] = 1;
        }
    }

    if (j < len2 && s2[j] == s3[i + j])
    {
        if (solve(s1, s2, s3, len1, len2, i, j + 1, dp))
        {
            return dp[i][j] = 1;
        }
    }

    return dp[i][j] = 0;
}
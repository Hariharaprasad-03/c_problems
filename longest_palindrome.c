#include <stdio.h>
#include <stdlib.h>

int str_len(const char *s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

int expandFromCenter(const char *s, int left, int right)
{
    while (left >= 0 && s[right] != '\0' && s[left] == s[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}

char *longestPalindrome(const char *s)
{
    int start = 0, end = 0;
    int len = str_len(s);

    for (int i = 0; i < len; i++)
    {
        int len1 = expandFromCenter(s, i, i);     // odd length
        int len2 = expandFromCenter(s, i, i + 1); // even length

        int maxLen = (len1 > len2) ? len1 : len2;

        if (maxLen > end - start)
        {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }

    int finalLen = end - start + 1;
    char *res = (char *)malloc(finalLen + 1);

    int ind = 0;
    for ( const char *st = s + start; ind < finalLen; st++)
    {
        res[ind++] = *st;
    }
    res[finalLen] = '\0';
    return res;
}

int main()
{
    char s[100];
    printf("Enter string: ");
    scanf("%s", s);

    char *ans = longestPalindrome(s);
    printf("Longest palindromic substring: %s\n", ans);
    free(ans);
    return 0;
}

// dhanush than dhanush than 
//dhanush than mass ee!
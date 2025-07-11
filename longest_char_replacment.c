#include <stdio.h>

int longest_replacement(char *s, int len, int k)
{
    int l = 0, r = 0, max_len = 0, max_freq = 0;

    int hash[26];

    for (r = 0; r < len; r++)
    {
        hash[s[r] - 'A']++;

        if (max_freq < hash[s[r] - 'A'])
        {
            max_freq = hash[s[r] - 'A'];
        }

        while ((r - l + 1) - max_freq > k)
        {
            hash[s[l]]--;
            max_freq = 0;
            l++;

            for (int i = 0; i < 26; i++)
            {
                if (hash[i] > max_freq)
                {
                    max_freq = hash[i];
                }
            }
        }
        if (r - l + 1 > max_len)
        {
            max_len = r - l + 1;
        }
    }
    return max_len;
}

int longest_replacement2(char *s, int len, int k)
{
    int l = 0, r = 0, max_len = 0, max_freq = 0;

    int hash[26];

    for (r = 0; r < len; r++)
    {
        hash[s[r] - 'A']++;

        if (max_freq < hash[s[r] - 'A'])
        {
            max_freq = hash[s[r] - 'A'];
        }

        // If window is invalid, shrink it--- because of invalid string
        if ((r - l + 1) - max_freq > k)
        {
            hash[s[l] - 'A']--;
            l++;
        }

        if (max_len < r - l + 1)
        {
            max_len = r - l + 1;
        }
    }

    return max_len;
}
int main()
{
    char input[20];
    scanf("%s", input);
    int k;
    scanf("%d", &k);
    int len = 0;

    while (input[len])
    {
        len++;
    }
    int ans = longest_replacement2(input, len, k);
    printf("%d\n", ans);
    return 0;
}
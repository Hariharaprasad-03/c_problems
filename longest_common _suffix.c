#include <stdio.h>

#define max_words 10
#define max_len 30
//  dhanush than mass !


#define INT_MAX 2147483647


int strlen_manual(char *input)
{
    int len = 0;
    while (input[len])
    {
        len++;
    }
    return len;
}

int longest_common_suffix(char s[][max_len], int n)
{
    int longest_suffix = INT_MAX;

    for (int i_string = 1; i_string < n; i_string++)
    {
        int i = strlen_manual(s[0]) - 1;
        int j = strlen_manual(s[i_string]) - 1;

        int suffix = 0;

        while (i >= 0 && j >= 0 && s[0][i] == s[i_string][j])
        {
            suffix++;
            i--;
            j--;
        }

        if (suffix < longest_suffix)
        {
            longest_suffix = suffix;
        }
    }

    return longest_suffix;
}

int main()
{

    char inputs[max_words][max_len];

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", *(inputs + i));
    }

    int ans = longest_common_suffix(inputs, n);

    n = strlen_manual(inputs[0]);

    for (int i = n - ans; i < n; i++)
    {
        printf("%c", inputs[0][i]);
    }
    return 0;
}
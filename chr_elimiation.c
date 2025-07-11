#include <stdio.h>

int str_len(char *s)
{
    int len = 0;
    while (s[len] != '\0')
    {

        len++;
    }
    return len;
}

void leftshift(char *s, int index)
{
    for (int i = index; s[i]; i++)
    {
        s[i] = s[i + 1];
    }
}

int main()
{

    char str1[10];
    char str2[10];

    scanf("%s", str1);
    scanf("%s", str2);

    int hash1[26] = {0};

    int len1 = str_len(str1);
    int len2 = str_len(str2);

    for (int i = 0; i < len2; i++)
    {
        hash1[str2[i] - 'a']++;
    }

    for (int i = 0; i < len1; i++)
    {
        if (hash1[str1[i] - 'a'] >= 1)
        {
            leftshift(str1, i);
            len1--;
        }
    }

    for (int i = 0; str1[i]; i++)
    {
        printf("%c", str1[i]);
    }

    return 0;
}
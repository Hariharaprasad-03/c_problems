#include <stdio.h>
int strlen(char *s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

void remove_dup(char *s, int n)
{
    int l = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            l++;
            s[l] = s[i];
        }
    }
    s[++l] = '\0';
}

int main()
{
    char input[100];
    scanf("%s", input);

    remove_dup(input, strlen(input));

    printf("\n%s\n", input);
    return 0;
}
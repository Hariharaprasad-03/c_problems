#include <stdio.h>
#include <stdlib.h>

void reverse_words(char *s, char *ans, int *i)
{
    if (*s == '\0')
    {
        return;
    }
    char *start = s;
    while (*s != ' ' && *s != '\0')
    {
        s++;
    }

    char *next = s;
    while (*next == ' ')
        next++;

    reverse_words(next, ans, i);

    while (*start != ' ' && *start != '\0')
    {
        ans[*i] = *start;
        (*i)++;
        start++;
    }

    ans[*i] = ' ';
    (*i)++;
}

int str_len(char *s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

int main()
{
    char input[100];
    scanf("%[^\n]", input);

    char *ans = (char *)malloc(str_len(input) + 2);
    int index = 0;

    reverse_words(input, ans, &index);
    ans[index] = '\0';

    printf("\n%s\n", ans);

    free(ans);
    return 0;
}

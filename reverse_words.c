#include <stdio.h>
#include <stdlib.h>

int str_len(char *s)
{
    int len = 0;
    while (s[len])
        len++;
    return len;
}

void reverse_words(char *a, int n, char *ans, int *i)
{
    if (*a == '\0')
        return;

    char store[100];
    int ind = 0;

    char *start = a;

    while (*start != ' ' && *start != '\0')
    {
        store[ind++] = *start++;
    }

    store[ind++] = ' ';

    // Recursive call 
    reverse_words((*start == ' ') ? start + 1 : start, n, ans, i);

    for (int c = 0; c < ind; c++)
        ans[(*i)++] = store[c];
}

int main()
{
    char input[100];

    scanf("%[^\n]", input);
    int len = str_len(input);

    char *ans = (char *)malloc(sizeof(char) * len + 2); //+2 for null sapcing 
    int index = 0;

    reverse_words(input, len, ans, &index);
    ans[index + 1] = '\0';

    printf("%s", ans);

    return 0;
}
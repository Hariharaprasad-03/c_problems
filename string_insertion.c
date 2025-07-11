#include <stdio.h>

int str_len(char *s)
{
    int len = 0;
    while (s[len])
    {
        len++;
    }

    return len;
}

void insert(char *s, char key, int pos)
{
    int len = str_len(s);

    for (int i = len; i >= pos; i--)
    {
        s[i + 1] = s[i];
    }
    s[pos] = key;
}

int main()
{
    char input[100];
    char key;
    int pos;

    scanf("%s", input);
    scanf(" %c", &key);
    scanf("%d", &pos);

    insert(input, key, pos);

    printf("\n%s\n", input);

    return 0;
}
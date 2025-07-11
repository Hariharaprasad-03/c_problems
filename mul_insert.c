#include <stdio.h>

void remove_vowels(char *s, int len);
int str_len(char *s);
void insert(char *s, char key, int pos);

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    char input[100];

    scanf("%s", input);

    remove_vowels(input, str_len(input));

    printf("\n%s\n", input);

    for (int i = 3; i < str_len(input); i += 4)
    {
        insert(input, '-', i);
    }

    printf("\n%s\n", input);
    return 0;
}

void remove_vowels(char *s, int len)
{
    int l = 0;

    for (int r = 0; r < len; r++)
    {
        if (!(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u'))
        {
            swap(&s[r], &s[l]);
            l++;
        }
    }
    s[l] = '\0';
}

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

    if (pos >= len)
    {
        return;
    }

    for (int i = len; i >= pos; i--)
    {
        s[i + 1] = s[i];
    }
    s[pos] = key;
}
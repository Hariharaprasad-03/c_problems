#include <stdio.h>

char *manual_fgets(char *str, int n, FILE *stream)
{
    if (str == NULL || n <= 0 || stream == NULL)
    {
        return NULL;
    }

    int i = 0;
    int ch;

    while (i < n - 1)
    {
        ch = getc(stream); // read one character from stream

        if (ch == EOF)
        {
            if (i == 0)
            {
                return NULL;
            }
            break; // break and terminate the string
        }

        str[i++] = (char)ch;

        if (ch == '\n')
        {
            break; // stop reading after newline
        }
    }

    str[i] = '\0'; // null-terminate the string
    return str;
}
int main()
{
    char buffer[100];
    char *p = manual_fgets(buffer, 50, stdin);
    printf("%s", p);
    return 0;
}
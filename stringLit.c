#include <stdio.h>
int main()
{
    char s[6] = "hello";
    char t[6];
    int i = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        t[i] = s[i];
    }
    t[i] = '\0';
    printf("%s", t);
    return 0;
}
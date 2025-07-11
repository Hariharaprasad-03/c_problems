#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
char *palindrome(char *s)
{
    char *start = s;
    char *l = s;
    int len = 0;
    while (l[len])
        len++;
    char *ans = malloc(len);
    char *end = s + len - 1;

    for (int i = 0; i < len; i++)
    {
        *(ans + i) = *(s + len - 1 - i);
    }
    return ans;
}
int main()
{
    char a[10];
    scanf("%s", a);
    char *p = palindrome(a);
    printf("%s", p);
    return 0;
}
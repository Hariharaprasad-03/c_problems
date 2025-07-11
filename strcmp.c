#include <stdio.h>
#include <stdbool.h>

int scmp(char *a, char *b)
{
    char *p, *p1;
    p = a;
    p1 = b;
    while (*p != '\0' || *p1 != '\0')
    {
        if (*p == *p1)
        {
            p++;
            p1++;
        }
        else if (*p < *p1)
            return 1;
        else
            return -1;
    }
    if (*p) return -1;
    if (*p1) return 1;
    return 0;
}

int main()
{
    char a[5] = "abcd";
    char b[5] = "abc";
    int ans = scmp(a, b);
    printf("%d\n", ans);
    return 0;
}
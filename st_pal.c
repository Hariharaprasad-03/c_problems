#include <stdio.h>
#include <stdbool.h>

bool palindrome(char *s)
{
    char *start = s;
    char *l = s;
    int len = 0;
    while (l[len])
        len++;
    char *end = s + len - 1;
    bool ans = true;
    for (char *p = s; p <= end; p++)
    {
        if (*p != *end--)
        {
            ans = false;
        }
    }
    return ans;
}
int main()
{
    char a[10];
    scanf("%s", a);
    bool p = palindrome(a);
    printf("%d", p);
    return 0;
}
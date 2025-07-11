#include <stdio.h>
#include <stdbool.h>

bool subs(char *a, char *b)
{
    int i, j;
    bool ans;
    for (i = 0; a[i] != '\0'; i++)
    {
        for (j = 0; b[j] != '\0'; j++)
        {

            if (a[j + i] != b[j])
                
                break;
        }
        if (b[j] == '\0')
            return true;
    }

    return false;
}

int main()
{
    char a[10] = "banana";
    char b[10] = "ban";
    bool ans;
    ans = subs(a, b);
    printf("%d", ans);
    return 0;
}
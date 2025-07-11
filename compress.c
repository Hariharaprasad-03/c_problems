#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *compress(char *s, int len)
{
    char *ans = (char *)malloc(2 * len);
    char *stack = (char *)malloc(len);

    int stp = len;
    int atp = 0;

    for (int i = 0; i < len; i++)
    {
        if (stp == len || s[i] == stack[stp])
        {
            stack[--stp] = s[i];
        }
        else
        {
            char ch = stack[stp];
            int cnt = len - stp;
            ans[atp++] = ch;

            char temp[10];
            sprintf(temp, "%d", cnt);
            for (int j = 0; temp[j]; j++)
                ans[atp++] = temp[j];

            stp = len;
            stack[--stp] = s[i];
        }
    }

    // Final process

    if (stp < len)
    {
        char ch = stack[stp];
        int cnt = len - stp;
        ans[atp++] = ch;

        char temp[10];
        sprintf(temp, "%d", cnt);
        for (int j = 0; temp[j]; j++)
            ans[atp++] = temp[j];
    }

    ans[atp] = '\0';

    free(stack);
    return ans;
}

char *compress2(char *s, int len)
{
    char *ans = (char *)malloc(2 * len);
    int atp = 0;

    for (int i = 0; i < len;)
    {
        char ch = s[i];
        int count = 0;

        while (i < len && s[i] == ch)
        {
            count++;
            i++;
        }

        ans[atp++] = ch;
        ans[atp++] = count + '0';
    }

    ans[atp] = '\0';
    return ans;
}
int main()
{
    char a[10];
    scanf("%s", a);
    char *p = compress(a, 10);
    printf("%s", p);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int str_len(char *s)
{
    int i = 0;
    while (s[i])
    {
        /* code */
        i++;
    }
    return i;
}
char *compress(char *s)
{

    char *ans = (char *)malloc(str_len(s) * 2);
    int ind = 0;
    
    for (int i = 0; s[i];)
    {
        char ch = s[i];
        int cnt = 0;

        while (s[i] == ch)
        {
            cnt++;
            i++;
        }

        ans[ind++] = ch;
        ans[ind++] = cnt + '0';
    }
    ans[ind] = '\0';
    return ans;
}

int main()
{
    char input[100];
    printf("enter string to compress:");
    scanf("%s", input);

    char *ans = compress(input);

    printf("\n compressed string :%s\n", ans);

    free(ans);
    return 0;
}
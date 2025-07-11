#include <stdio.h>
#include <stdlib.h>

char *remove_dup(char *s)
{
    int freq[26] = {0};

    char *st = s;
    char *ans = (char *)malloc(100);
    int i = 0;

    while (*st)
    {    
        freq[(*st) - 'a']++;
        if (freq[(*st) - 'a'] == 1)
        {
            ans[i++] = *st;
    
        }
        st++;
    }

    ans[i] = '\0';
    return ans;
}

int main()
{
    char input[100];
    scanf("%[^\n]", input);

    char *ans = remove_dup(input);

    printf("\n%s\n", ans);

    free(ans);
    return 0;
}

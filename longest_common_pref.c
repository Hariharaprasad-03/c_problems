#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[10][10];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf(" %s", input[i]);
    }

    int is_same = 1;
    char *ans = (char *)malloc(10);
    int ind = 0;

    int j = 0;
    while (is_same)
    {
        int i = 0;
        while (i + 1 < n && input[i + 1][j] == input[i][j])
        {
            i++;
        }

        if (i != n - 1)
        {
            is_same = 0;
        }

        if (!is_same)
        {
            break;
        }
        ans[ind++] = input[i][j];
        j++;
    }

    ans[ind] = '\0';

    printf("%s", ans);

    return 0;
}
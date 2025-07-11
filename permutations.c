#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

void solve(char *s, int n, int l, char **ans, int *index)
{
    if (l == n)
    {
        ans[*index] = (char *)malloc((n + 1) * sizeof(char)); // +1 for '\0'

        for (int j = 0; j < n; j++)
        {
            ans[*index][j] = s[j];
        }

        ans[*index][n] = '\0';
        (*index)++;

        return;
    }

    for (int i = l; i < n; i++)
    {
        swap(&s[l], &s[i]);
        solve(s, n, l + 1, ans, index);
        swap(&s[l], &s[i]);
    }
}

char **permutations(char *s, int n, int l)
{
    int rows = fact(n);
    char **ans = (char **)malloc(sizeof(char *) * rows);
    int index = 0;

    solve(s, n, l, ans, &index);

    return ans;
}

int main()
{
    char s[10];
    printf("give input\n");

    scanf("%s", s);
    int len = 0;

    while (s[len])
    {
        len++;
    }

    printf("Printing all permutations:\n");
    
    char **ans = permutations(s, len, 0);
    int total = fact(len);

    for (int i = 0; i < total; i++)
    {
        printf("%s\n", ans[i]);

        free(ans[i]); // free array
    }
    free(ans); // free pointers odf arrays

    return 0;
}

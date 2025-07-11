// letter case permutations

#include <stdio.h>
#include <stdlib.h>

char *dialpad[11] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int str_len(char *s)
{
    int i = 0;

    while (s[i])
    {
        i++;
    }
    return i;
}

void letter_combine(char *input, int len, int i, char *cur, int cur_len)
{ 
    if (i == len)
    {
        cur[cur_len] = '\0';

        printf("%s\n", cur);

        return;
    }

    char ch = input[i];
    int index = input[i] - '0';
    char *s = dialpad[index];
    int n = str_len(s);

    for (int j = 0; j < n; j++)
    {
        cur[cur_len] = s[j];
        letter_combine(input, len, i + 1, cur, cur_len + 1); // next pass for combination 
    }
}

int main()
{
    char input[100];
    scanf("%s", input);

    int n = str_len(input);

    char *cur = (char *)malloc(100);

    letter_combine(input, n, 0, cur, 0);


    return 0;
}

#include <stdio.h>

int str_len(char *s)
{
    int i = 0;

    while (s[i])
    {
        i++;
    }
    return i;
}

int main()
{

    char input[100];
    scanf("%s", input);

    int n = str_len(input);

    long ans = 0;
    long pow = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            ans += (input[i] - 'A') + 1;
            pow*=26;

            continue;
        }

        long temp =((input[i] - 'A') + 1) *pow;
        pow*=26;

        ans += temp;
    }
    

    printf("%ld", ans);
    return 0;
}
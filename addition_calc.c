#include <stdio.h>

int phrase(char **s)
{
    int num = 0;
    while (**s >= '0' && **s <= '9')
    {
        num = num * 10 + (**s - '0');
        (*s)++;
    }
    (*s)--;
    return num;
}

int solve(char **s)
{
    int res = 0;
    int sign = 1;

    while (**s && **s != ')')
    {
        if (**s >= '0' && **s <= '9')
        {
            res += sign * phrase(s);
            sign = 1;
        }
        else if (**s == '-')
        {
            sign = -1;
        }
        else if (**s == '+')
        {
            sign = 1;
        }
        else if (**s == '(')
        {
            (*s)++;
            res += sign * solve(s);
            sign = 1;
        }
        (*s)++;
    }
    return res;
}

int evaluate(char *s)
{

    return solve(&s);
}

int main()
{
    char exp[100];
    scanf("%s", exp);

    int ans = evaluate(exp);

    printf("ans = %d\n", ans);
    return 0;
}

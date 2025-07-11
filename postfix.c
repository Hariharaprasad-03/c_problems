#include <stdio.h>
#include <stdlib.h>

int len(char *s);
char *convert_postfix(char *exp, int n);
int evaluate_postfix(char *exp, int n);
int precd(char s);
int operation(int op1, int op2, char op);

int main()
{
    char input[100];
    scanf("%s", input);

    int n = len(input);
    char *postfix = convert_postfix(input, n);

    int ans = evaluate_postfix(postfix, len(postfix));
    printf("%d\n", ans);

    free(postfix); 
    return 0;
}

int len(char *s)
{
    int length = 0;
    while (s[length])
    {
        length++;
    }
    return length;
}

char *convert_postfix(char *exp, int n)
{
    char stack[100];
    int top = -1;

    char *ans = (char *)malloc(100);
    int ind = 0;
    int i = 0;

    while (i < n)
    {
        char ch = exp[i];

        if (ch >= '0' && ch <= '9')
        {
            ans[ind++] = ch;
        }

        else if (ch == '(')
        {
            stack[++top] = ch;
        }

        else if (ch == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                ans[ind++] = stack[top--];
            }
            
            top--; 
        }

        else 
        {
            while (top >= 0 && precd(ch) <= precd(stack[top]) && stack[top] != '(')
            {
                ans[ind++] = stack[top--];
            }
            stack[++top] = ch;
        }

        i++;
    }

    
    while (top >= 0)
    {
        if (stack[top] != '(')
            ans[ind++] = stack[top];
        top--;
    }

    ans[ind] = '\0';
    return ans;
}

int precd(char s)
{
    switch (s)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0; 
    }
}

int evaluate_postfix(char *exp, int n)
{
    int stack[100];
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            stack[++top] = exp[i] - '0';
        }
        else
        {
            int op1 = stack[top--];
            int op2 = stack[top--];
            int res = operation(op2, op1, exp[i]);
            stack[++top] = res;
        }
    }
    return stack[top];
}

int operation(int op1, int op2, char op)
{
    switch (op)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    default:
        return 0;
    }
}

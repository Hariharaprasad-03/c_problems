#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *decode_string(char *s, int len)
{
    char *stack = malloc(100);
    int countStack[100];

    int top = -1;
    char temp[100];

    int i = 0;
    int countTop = -1;

    while (i < len)
    {

        if (s[i] >= '0' && s[i] <= '9')
        {
            int num = 0;
            while (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + s[i++] - '0';
            }
            
            countStack[++countTop] = num;
        }

        else if (s[i] == '[')
        {
            stack[++top] = s[i++];
        }

        else if (s[i] == ']')
        {
            int templen = 0;
            while (top >= 0 && stack[top] != '[')
            {
                temp[templen++] = stack[top--];
            }

            temp[templen] = '\0'; // null character
            stack[top--];         //  for  pop out '['

            int cnt = countStack[countTop--];
            for (; cnt > 0; cnt--)
            {
                for (int j = templen - 1; j >= 0; j--)
                {
                    stack[++top] = temp[j];
                }
            }
            i++;
        }
        else
        {
            stack[++top] = s[i];
            i++;
        }
    }
    stack[++top] = '\0';

    return stack;
}
int main()
{
    char a[20];
    scanf("%s", a);
    int len = strlen(a);

    char *p = decode_string(a, len);

    printf("\n%s\n", p);
    return 0;
}

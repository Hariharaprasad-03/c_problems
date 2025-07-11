#include <stdio.h>

int main()
{
    char str[100];
    int a = 0;

    // Step 1: Read input character by character
    // char ch;

    // while ((ch = getchar()) != '\n' && (ch != EOF) && (len < 99))
    // {
    //     str[len++] = ch;
    // }

    // str[len] = '\0';

    scanf("%[^\n]", str);

    int len = 0;
    while (str[len++])
        ;

    int start = 0;
    for (int i = 0; i <= len; i++)
    {

        if (str[i] == ' ' || str[i] == '\0')
        {
            int end = i - 1;

            while (start < end)
            {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            start = i + 1; // next word starts after space
        }
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}

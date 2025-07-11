#include <stdio.h>

void swap(char *a, char *b)
{

    char temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{

    char binary[100];
    scanf("%s", binary);

    int len = 0;

    while (binary[len])
    {
        len++;
    }

    int l = 0, r = len - 1;

    for (int i = 0; binary[i]; i++)
    {

        if (binary[i] == '1')
        {
            swap(&binary[i], &binary[r]);
            r--;
            break;
        }
    }

    for (int i = 0; i <= r; i++)
    {

        if (binary[i] == '1')
        {
            swap(&binary[i], &binary[l]);
            l++;
        }
    }

    printf("%s", binary);
    return 0;
}
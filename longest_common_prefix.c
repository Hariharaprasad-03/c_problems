#include <stdio.h>
#include <stdlib.h>

int strcmp(char *a, char *b)
{
    while (*a && *b && *a == *b)
    {
        a++;
        b++;
    }
    return *a - *b;
}

void str_cpy(char *destination, char *source)
{
    int i = 0;

    while (source[i])
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

void swap(char *a, char *b)
{
    char temp[30];
    str_cpy(temp, a);
    str_cpy(a, b);
    str_cpy(b, temp);
}


int main()
{
    char input[10][10];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf(" %s", input[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int pos = i;
        while (pos > 0 && strcmp(input[pos], input[pos - 1]) < 0)
        {
            swap(input[pos], input[pos - 1]);
            pos--;
        }
    }

    int i = 0;
    char *s1 = input[0];
    char *s2 = input[n - 1];

    for (int i = 0; i < n; i++)
    {   
        printf(" %s", input[i]);
    }
    printf("\n");

    while (*s1 && *s2 && *s1 == *s2)
    {
        i++;
        s1++;
        s2++;
    }

    for (int j = 0; j < i; j++)
    {
        printf("%c", input[0][j]);
    }

    return 0;
}
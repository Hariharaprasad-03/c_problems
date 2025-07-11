#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void charater_sort(char *s, int len);
int main()
{
    char a[27] = "zyxwvutsrqponmlkjihgfedcba";
    charater_sort(a, 26);
    printf("%s\n", a);
    return 0;
}
void charater_sort(char *s, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        int pos = i;
        while (pos > 0 && pos < len && *(s + pos) < *(s + pos - 1))
        {
            swap((s + pos), (s + pos - 1));
            pos--;
        }
    }
}
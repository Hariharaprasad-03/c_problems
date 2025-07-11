#include <stdio.h>

int main()
{
    char b[] = "abcd";
    char a[] = {'A', 'B', 'C', 'D'};
    char *ppp = &a[0];
    // ppp += 1;
    // ppp -= 1;
    int m = sizeof(b) / sizeof(b[0]);
    *ppp++;
    printf("%d\n", m);                  // Line 1
    printf("%c %c\n ", *++ppp, ++*ppp); // Line 2
    printf("%c\n", *ppp);               // Line 1

    for (int i = 0; i < 5; i++)
    {
        printf("%c", a[i]);
    }
    return 0;
}
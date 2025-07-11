#include <stdio.h>

static int i = 42; // File-scope static
// static int i = 0;
// int i = 27;
int main()
{
    // int i = 25;
    int a = -3 - -3;
    double d=10;
    printf("%d\n",d);
    int b[5] = {1, 2, 3, 4, 5};
    int *p = &b[0];
    unsigned long x = 100000101010101;
    printf("%lu\n", x);
    long long i = 100000000000;
    printf("%lld\n", i);

    // printf("%d,%d\n",  ++*p);
    for (int i = 0; i < 5; i++)
    {
        printf("%d", *(p + i));
    }

    return 0;
}

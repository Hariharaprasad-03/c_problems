#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}
void hello()
{
    printf("hello\n");
}
int main()
{
    int c;
    int (*p)(int, int);
    p = &add;
    c = (*p)(2, 3);
    printf("%d\n", c);
    void (*ptr)();
    ptr = hello;
    ptr();
    return 0;
}
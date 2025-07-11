#include <stdio.h>
#include <string.h>

int main()
{
    char str[20] = "dhanush";

    memset(str + 7, 'x', 5);

    printf("After memset: %s\n", str);
    return 0;
}

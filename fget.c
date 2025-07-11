#include <stdio.h>

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("You entered: ");
    puts(str);
    return 0;
}

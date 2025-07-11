#include <stdio.h>

void add(int a, int b) { printf("Sum: %d\n", a + b); }
void sub(int a, int b) { printf("Diff: %d\n", a - b); }

int main()
{
    void (*operations[2])(int, int) = {add, sub};

    operations[0](5, 3); 
    operations[1](5, 3); 

    return 0;
}

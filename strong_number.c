#include <stdio.h>

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{

    int n;
    scanf("%d", &n);

    int temp = n;
    int strong_number = 0;
    while (temp > 0)
    {
        int digit = temp % 10;
        strong_number += fact(digit);
        temp /= 10;  
    }

    if (strong_number == n)
    {
        printf(" %d strong_number ", n);
    }
    else
    {
        printf("%d  is not strong number ", n);
    }
}
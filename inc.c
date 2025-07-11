#include <stdio.h>

int main()
{
    int n;
    int prev = -1;

    scanf("%d", &n);

    int ans = 1;
    int temp = n;

    while (temp)
    {
        int digit = temp % 10;

        if (prev == -1)
        {
            prev = digit;
        }

        else
        {
            if (prev < digit)
            {
                ans = 0;
                break;
            }
            prev = digit;
        }
        temp /= 10;
    }

    printf("%d", ans);
    return 0;
}
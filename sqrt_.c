#include <stdio.h>

int main()
{

    int input;
    scanf("%d", &input);
    int left = 1;
    int right = input;

    while (left < right)
    {
        int mid = (left + right) / 2;

        if (mid * mid == input)
        {
            printf("%d", mid);
            break;
        }
        else if (mid * mid > input)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return 0;
}
#include <stdio.h>

int main()
{

    int input[25];
    int input_len;
    printf("input lenght of an array:");
    scanf("%d", &input_len);

    int sum = 0;

    for (int i = 0; i < input_len; i++)
    {
        scanf("%d", input + i);
        sum += *(input + i);
    }

    int rightsum = 0;
    int ans = -1;

    for (int i = input_len - 1; i >= 0; i--)
    {
        rightsum += input[i];

        if (sum - rightsum == rightsum-input[i])
        {
            ans = i;
        }
    }
    
    printf("%d", ans);
    return 0;
}
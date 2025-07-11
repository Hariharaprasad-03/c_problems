#include <stdio.h>
#include <string.h>

int longest(char *s, int k)
{
    int n = strlen(s);
    int len = 0;
    int pow = 1;
    int val = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            count++;
    }

    
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            if (pow > k)
                break;

            val += pow;
            if (val <= k)
                count++;
            else
                break;

            pow <<= 1;  
        }
        
    }

    return count;
}

int main()
{
    char input[100];
    int k;

    scanf("%s", input);
    scanf("%d", &k);

    int ans = longest(input, k);
    printf("ans = %d\n", ans);

    return 0;
}

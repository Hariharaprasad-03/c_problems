#include <stdio.h>

int main()
{

    int n1, n2, l = 0, r = 0;
    int input1[25], input2[25];

    scanf("%d", &n1);
    scanf("%d", &n2);

    for (int i = 0; i < n1; i++)
    {
        scanf("%d", input1 + i);
    }

    for (int i = 0; i < n2; i++)
    {
        scanf("%d", input2 + i);
    }

    while (l < n1 && r < n2)
    {

        if (input1[l] == input2[r])
        {
            printf("%d ", input1[l]);
            l++;
            r++;
        }
        
        else if (input1[l] < input2[r])
        {
            l++;
        }

        else
        {

            r++;
        }
    }
    return 0;
}
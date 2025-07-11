#include <stdio.h>

int main()
{
    int input[30];
    int input_len;
    int k;

    printf("enter no of inputs:");
    scanf("%d", &input_len);
    printf("\n enter k value:");
    scanf("%d", &k);

    for (int i = 0; i < input_len; i++)
    {
        scanf("%d", input + i);
    }

    int max_prod = 0;
    int l = 0;
    int prod = 1;
    int index = -1;

    for (int r = 0; r < input_len; r++)
    
    {
        prod *= input[r];

        if (r > k - 1)    
        {
            prod /= input[l];
            l++;
        }

        if ( prod > max_prod )
        {
            index = l;
            max_prod = prod;
        }
    }

    printf("%d\n", max_prod);          

    for (int i = index; i < index + k; i++)    // printing subarray 
    {
        printf("%2d", input[i]);
    }
    return 0;
}
#include <stdio.h>

int compare(int a, int b)
{
    return a < b;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    scanf("%d", &n);

    int input[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", input + i);
    }

    for (int i = 0; i < n; i++)
    {
        if (i&1 == 0)                            // if even
        {

            int pos = i;

            while (pos - 2 >= 0 && input[pos] < input[pos - 2])
            {
                swap(&input[pos], &input[pos - 2]);
                pos = pos - 2;
            }
        }

        else                                          // if odd 
        {
            int pos = i;
            while (pos - 2 > 0 && input[pos] > input[pos - 2])
            {
                swap(&input[pos], &input[pos - 2]);
                pos = pos - 2;
            }
     
        }
    }

    for (int i = 0; i < n; i++)                     // printing answer;
    {
        printf("%d", *(input + i));
    }

    return 0;
}
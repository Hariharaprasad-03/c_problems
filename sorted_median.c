#include <stdio.h>
#include <limits.h>
#include <math.h>

void get_input(int *inputs, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", inputs + i);
    }
}

int median(int * a, int *b, int n1, int n2)
{
    int l = 0;
    int r = n1;
    
    while (l <= r)
    {
        int mid1 = (l + r) / 2;
        int mid2 = (n1 + n2 + 1) / 2 - mid1;

        int leftmax1  = mid1 == 0 ? INT_MIN : a[mid1 - 1];
        int leftmax2  = mid2 == 0 ? INT_MIN : b[mid2 - 1];
        int rightmin1 = mid1 == n1 ? INT_MAX : a[mid1];
        int rightmin2 = mid2 == n2 ? INT_MAX : b[mid2];

        if (leftmax1 <= rightmin2 && leftmax2 <= rightmin1)
        {
            return (n1 + n2) % 2 == 0 ? (fmin(rightmin1, rightmin2) + fmax(leftmax1, leftmax2)) / 2 : fmax(leftmax1, leftmax2);
        }
        else if (leftmax1 > rightmin2)
        {
            r = mid1 - 1;
        }
        else
        {
            l = mid1 + 1;
        }
    }
}

int main()
{

    int n1;
    int n2;

    scanf("%d", &n1);
    scanf("%d", &n2);

    int input1[n1];
    int input2[n2];

    get_input(input1, n1);
    get_input(input2, n2);

    int ans = median(input1, input2, n1, n2);

    printf("%d ", ans);

    return 0;
}
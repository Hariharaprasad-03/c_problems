#include <stdio.h>
#include <stdlib.h>

int *solve(int *temp, int len)
{
    int *answer = (int *)calloc(len, sizeof(int));
    int stack[100];
    int top = -1;

    for (int r = 0; r < len; r++)
    {

        while (top >= 0 && temp[stack[top]] < temp[r])
        {
            int index = stack[top--];
            answer[index] = r - index;
        }
        stack[++top] = r;
    }
    return answer;
}

int main()
{
    int n;                                // input size
    printf("size of temprature array:");
    scanf("%d", &n);

    int tempratures[n];
    for (int i = 0; i < n; i++)           // input
    {
        scanf("%d", tempratures + i);
    }

    int *ans = solve(tempratures, n);      // ans

    for (int i = 0; i < n; i++)
    {

        printf("%2d", *(ans + i));
    }
    free(ans);                    //free memory 

    return 0;
}
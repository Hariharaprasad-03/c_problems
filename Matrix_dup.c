#include <stdio.h>
#include <stdlib.h>

int **remove_duplicates(int a[][10], int rows, int cols, int *end)
{
    int *marker = (int *)calloc(rows, sizeof(int));
    int **ans = (int **)malloc(sizeof(int *) * rows);

    for (int i = 0; i < rows; i++)
    {
        if (marker[i])
            continue;

        ans[*end] = (int *)malloc(sizeof(int) * cols);

        for (int c = 0; c < cols; c++)
        {
            ans[*end][c] = a[i][c];
        }

        (*end)++;

        for (int j = i + 1; j < rows; j++)
        {
            if (marker[j])
                continue;

            int k = 0;

            while (k < cols && a[i][k] == a[j][k])
            {
                k++;
            }
            if (k == cols)
            {
                marker[j] = 1;
            }
        }
    }

    free(marker);
    return ans;
}

int main()
{

    int rows;
    int cols;
    int input[10][10];

    scanf("%d", &rows);
    scanf("%d", &cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", (*(input + i) + j));
        }
    }

    int end = 0;
    int **ans = remove_duplicates(input, rows, cols, &end);

    for (int i = 0; i < end; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        free(ans[i]);
    }

    free(ans);

    return 0;
}
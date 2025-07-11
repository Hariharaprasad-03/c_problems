#include <stdio.h>
#include <stdlib.h>

int *spiral(int a[][10], int rows, int cols, int *k)
{
    int  r = 0,  c = 0;
    int dr = 0, dc = 1;
    int mark[10][10] = {0};

    int *res = (int *)calloc(rows * cols, sizeof(int));

    while (*k < rows * cols)
    {
        res[*k] = a[r][c];
        mark[r][c] = 1;
        (*k)++;

        if (!(r + dr >= 0 && r + dr < rows && c + dc >= 0 && c + dc < cols) || mark[r + dr][c + dc])
        {
            int temp = dr;
            dr = dc;
            dc = -temp;
        }

        r += dr;
        c += dc;
    }

    return res;
}

int main()
{
    int input[10][10];
    int rows;
    int cols;

    scanf("%d", &rows);
    scanf("%d", &cols);

    // int new [rows][cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", (*(input + i) + j));
        }
    }

    int k = 0;
    int *ans = spiral(input, rows, cols, &k);

    for (int i = 0; i < k; i++)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}
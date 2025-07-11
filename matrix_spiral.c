#include <stdio.h>
#include <stdlib.h>

int *spiral(int mat[][10], int rows, int cols, int *ind)
{

    int top = 0;
    int left = 0;
    int bottom = rows - 1;
    int right = cols - 1;

    int *ans = (int *)malloc(sizeof(int) * rows * cols);

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans[(*ind)++] = mat[top][i];
        }

        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans[(*ind)++] = mat[i][right];
        }

        right--;

        if (bottom < top)
        {
            break;
        }

        for (int i = right; i >= left; i--)
        {
            ans[(*ind)++] = mat[bottom][i];
        }

        bottom--;

        // if (left > right)
        // {
        //     break;
        // }

        for (int i = bottom; i >= top; i--)
        {
            ans[(*ind)++] = mat[i][left];
        }

        left++;
    }
    return ans;
}

int main()
{

    int n;
    int mat[10][10];
    int row, col;

    scanf("%d", &row);
    scanf("%d", &col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", (*(mat + i) + j));
        }
    }

    int index = 0;
    int *ans = spiral(mat, row, col, &index);

    for (int i = 0; i < index; i++)
    {

        printf("%d ", ans[i]);
    }

    return 0;
}
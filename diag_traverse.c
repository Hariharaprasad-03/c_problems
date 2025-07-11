#include <stdio.h>
#include <stdlib.h>

int *diag_traverse(int a[][10], int rows, int cols, int *k)
{
    int r = 0, c = 0;
    int dr = -1, dc = 1;

    int *ans = (int *)calloc(rows * cols, sizeof(int));

    while (*k < rows * cols)
    {
        ans[*k] = a[r][c];
        (*k)++;

        if (!(r + dr >= 0 && r + dr < rows && c + dc >= 0 && c + dc < cols))
        {

            if (dr < 0)
            {
                if (c + 1 < cols)
                {
                    c++;
                }

                else
                {
                    r++;
                }
            }
            else
            {
                if (r + 1 < rows)
                {
                    r++;
                }
                else
                {
                    c++;
                }
            }

            dr *= -1;
            dc *= -1;
        }
        else
        {
            r += dr;
            c += dc;
        }
    }

    return ans;
}

int main()
{
    int input[10][10];
    int rows;
    int cols;

    scanf("%d", &rows);
    scanf("%d", &cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", (*(input + i) + j));
        }
    }

    int k = 0;

    int *ans = diag_traverse(input, rows, cols, &k);

    for (int i = 0; i < k; i++)
    {
        printf("%d ", ans[i]);
    }
    free(ans);

    return 0;
}
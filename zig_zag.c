#include <stdio.h>

void zig_zag(int mat[][10], int n)
{
    int r = 0, c = 0;
    int top = 0;
    int dr = 1;
    int temp = 1;

    while (r < n && c < n)
    {
        mat[r][c] = temp++;

        if (!(r + dr >= top && r + dr < n))
        {
            if (dr > 0)
            {
                if (c + 1 >= n)
                {
                    break;
                }
                else
                {
                    c++;
                }
                dr *= -1;

                top++;
            }
            else
            {
                c++;
                r++;
                dr *= -1;
                top++;
            }
        }
        else
        {
            r += dr;
        }
    }
}

int main()
{

    int n;
    int mat[10][10];

    scanf("%d", &n);

    zig_zag(mat, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {

            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
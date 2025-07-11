#include <stdio.h>
#include <stdbool.h>

#define row 3
#define col 3

int main()
{
    int a[row][col] = { {10, 11, 11},
                        {12, 0, 13},
                        {0, 11, 11}  };

    bool firstcol = false;
    bool firstrow = false;

    for (int i = 0; i < row; i++)
    {
        if (a[0][i] == 0)
        {
            firstrow = true;
        }
    }

    for (int i = 0; i < col; i++)
    {

        if (a[i][0] == 0)
        {
            firstcol = true;
        }
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (a[i][j] == 0)
            {
                a[0][j] = 0;
                a[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (a[i][0] == 0 || a[0][j] == 0)
            {
                a[i][j] = 0;
            }
        }
    }

    if (firstcol)
    {
        for (int j = 0; j < col; j++)
        {
            a[j][0] = 0;
        }
    }

    if (firstrow)
    {
        for (int i = 0; i < row; i++)
        {
            a[0][i] = 0;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
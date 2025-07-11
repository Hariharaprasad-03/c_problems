#include <stdio.h>
#include <string.h>

void get_input(int table[][100], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &table[i][j]);
        }
    }
}

void get_exp(char *s)
{
    scanf("%s", s);
}

int operation(int a, int b, char op)
{
    switch (op)
    {
    case '>':
        return a > b;
    case '<':
        return a < b;
    case '=':
        return a == b;
    default:
        return 1; // Always true by default
    }
}

void go(int astrip, char operand, char operator, int table[][100], int col, int row, int num)
{
    int cols[100] = {0};
    int rows[100];

    for (int i = 0; i < row; i++)
        rows[i] = 1;

    if (astrip)
    {
        for (int i = 0; i < col; i++)
            cols[i] = 1;
    }
    else
    {
        int col_index = operand - 'A' + 1;
        if (col_index >= 0 && col_index < col)
            cols[col_index] = 1;
        else
            return;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (cols[j])
            {
                int val = table[i][j];
                if (!operation(val, num, operator))
                {
                    rows[i] = 0;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 25; i++)
        printf("-");
    printf("\n");

    for (int i = 0; i < row; i++)
    {
        if (rows[i])
        {
            for (int j = 0; j < col; j++)
            {
                if (cols[j] && rows[i])
                    printf("%d ", table[i][j]);
            }
            printf("\n");
        }
    }
}

void print(char *input, int table[100][100], int row, int col)
{
    char operand = 0;
    char operator = 0;
    int astrip = 0;
    int num = 0;

    for (int i = 0; input[i]; i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            operand = input[i];
        }
        else if (input[i] == '*')
        {
            astrip = 1;
        }

        else if (input[i] >= '0' && input[i] <= '9')
        {
            num = num * 10 + (input[i] - '0');
        }

        else
        {
            operator = input[i];
        }
    }

    go(astrip, operand, operator, table, col, row, num);
}

int main()
{
    char input[10];
    int table[100][100];
    int row, col;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);

    printf("Enter the matrix:\n");
    get_input(table, row, col);

    while (1)
    {
        printf("1. input filter  2. exit: ");
        int in;
        scanf("%d", &in);

        if (in == 1)
        {
            printf("Enter expression (e.g., A>50 or *B<60): \n");
            get_exp(input);
            print(input, table, row, col);
        }
        else
        {
            break;
        }
    }

    return 0;
}

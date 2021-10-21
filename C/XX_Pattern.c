#include <stdio.h>

/*
 * nos = Num. of spaces required in the triangle.
 * i   = Counter for the num. of characters to print in each row
 * skip= A flag for check whether to
 *       skip a character in a row.
 *
*/

int triangle(int nos, int i, int skip)
{
    char prnt = '*';
    int s, j;
    for (s = nos; s >= 1; s--)
    {
        printf("  ");
    }
    for (j = 1; j <= i; j++)
    {
        if (skip != 0)
        {
            if (i == 9 && j == 1)
            {
                continue;
            }
        }
        if (i == 1 || i == 9)
        {
            printf("%2c", prnt);
        }
        else if (j == 1 || j == i)
        {
            printf("%2c", prnt);
        }
        else
        {
            printf("  ");
        }
    }
    return 0;
}

int main()
{
    int i, nos = 0, nosp = -1, nbsp = -1;
    for (i = 9; i >= 1; (i = i - 2))
    {
        triangle(nos, i, 0);
        triangle(nosp, i, 1);
        triangle(nbsp, i, 1);
        printf("\n");
        nos++;
        nosp = nosp + 2;
        nbsp = nbsp + 2;
    }
    nos = 3, nosp = 5, nbsp = 5;
    for (i = 3; i <= 9; (i = i + 2))
    {
        triangle(nos, i, 0);
        triangle(nosp, i, 1);
        triangle(nbsp, i, 1);
        printf("\n");
        nos--;
        nosp = nosp - 2;
        nbsp = nbsp - 2;
    }
    return 0;
}

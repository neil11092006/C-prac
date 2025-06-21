#include <cs50.h>
#include <stdio.h>

int h;
int n;

int get_positive_int(void)
{

    do
    {
        h = get_int("Height: ");
    }
    while (h < 1);
    return h;
}

int main(void)
{

    get_positive_int();

    n = h;

    for (int row = 1; row <= h; row++)
    {
        for (int i = 0; i < n; i++)
        {
            printf(" ");
        }

        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k < row; k++)
        {
            printf("#");
        }

        printf("\n");
        n--;
    }
}
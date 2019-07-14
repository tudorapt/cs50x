#include <stdio.h>
#include <cs50.h>

void left_pyramid(int height, int row)
{
    for (int i = 0; i < height - row; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < row; i++)
    {
        printf("#");
    }
}

void right_pyramid(int row)
{
    for (int i = 0; i < row; i++)
    {
        printf("#");
    }
    printf("\n");
}

void gap(void)
{
    printf("  ");
}

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    for (int row = 1; row <= height; row++)
    {
        left_pyramid(height, row);
        gap();
        right_pyramid(row);
    }
}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pyramidHeight;
    do
    {
        pyramidHeight = get_int("Enter a number:\n");
    }
    while (pyramidHeight < 1 || pyramidHeight > 8);


    int v = pyramidHeight;

    for (int m = 1; m < pyramidHeight + 1; m++)
    {

// White Space
        for (int i = 1; i < v; i++)
        {
            printf(" ");
        }
        v--;
// Left Bricks
        for (int j = 0; j < m; j++)
        {
            printf("#");
        }

// Gap
        for (int k = 0; k < 1; k++)
        {
            printf("  ");
        }

//  Right Bricks
        for (int l = 0; l < m; l++)
        {
            printf("#");
        }

// new Row
        printf("\n");
    }

}
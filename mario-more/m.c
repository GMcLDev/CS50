#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pyramidHeight;
    do
    {
        pyramidHeight = get_int("Enter a number:\n");
    }
    while(pyramidHeight > 8);

int v = pyramidHeight;

for (int m = 0; m < pyramidHeight; m++)
{

// White Space
    for (int i = 0; i < v; i++)
        {
             printf(".");
        }
         v--;
         // new Row
    printf("\n");
    printf("%d\n", v);
}
}




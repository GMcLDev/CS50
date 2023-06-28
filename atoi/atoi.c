#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // sets length to length of input
    int length = strlen(input);

    // if string now one integer return converted from ascii
    if (length == 1)
    {
        return input[0] - 48;
    }

    // set variable to last char in stirng
    char last = input[length -1];

    // convert variable to converted ascii
    int converted = last - 48;

    // remove last digit
    input[length-1] = '\0';

    // return converted variable + 10 * recursive function and input
    return converted + 10 * (convert(input));


}
#include <cs50.h>
#include <stdio.h>


int main(int argc, string argv[])
{

    int weeks = get_int("Number of weeks taking cs50:\n");
    int hours[weeks];
    float sum = 0;
    float total = 0;

    for (int j = 0; j < weeks; j++)
    {
        float hour = get_int("Wweek %i HW hours: ", j);
        hours[j] = hour;
        sum += hours[j];
    }

    float average = sum / weeks;
    total = sum;

    char option = get_char("Enter T for total hours, A for average hours per week:\n");

    if (option == 'T')
    {
        printf("Total: %.2f\n", total);
    }
    if (option == 'A')
    {
        printf("Average: %.2f\n", average);
    }
}

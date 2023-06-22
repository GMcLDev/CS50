#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int populationStartSize;
    do
    {
        populationStartSize = get_int("What is the starting size of the population?:\n");
    }
    while (populationStartSize < 9);

    int populationEndSize;
    do
    {
        populationEndSize = get_int("What is the final size of the population?:\n");
    }
    while (populationEndSize < populationStartSize);

    int currentYear = 0;
    int currentPopulation = 0;
    currentPopulation = populationStartSize;

    if (populationStartSize == populationEndSize)
    {
        printf("Years: 0\n");
    }
    else
    {
        while (currentPopulation < populationEndSize)
        {

            int currentBirths = currentPopulation  / 3;
            int currentDeaths = currentPopulation / 4;
            currentPopulation += currentBirths;
            currentPopulation -= currentDeaths;
            currentYear++;
        }
    }

    printf("Years: %d\n", currentYear);
}

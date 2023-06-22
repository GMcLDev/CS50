#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <ctype.h>

// functions
int letters(string text);
int words(string text);
int sentences(string text);

//int index3(int letters2, int sentences2, int words2); // Might fix this later

// main
int main(void)
{
    string text = get_string("Enter text: \n");
    float words2 = words(text); // words
    float sentences2 = sentences(text) ; // sentences
    float letters2 = letters(text); // characters

    // I wanted this as a seperate function but can't figure it out
    float l = letters2 / words2 * 100;
    float s = sentences2 / words2 * 100;
    float index2 = 0.0;
    index2 = 0.0588 * l - 0.296 * s - 15.8;
    int rounded = round(index2);
    if (rounded >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (rounded < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", rounded);
    }

}

// return letters
int letters(string text)
{
    int length = strlen(text);
    int letterCount = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letterCount++;
        }
    }
    return letterCount;
}

// return words
int words(string text)
{
    int length = strlen(text);
    int wordCount = 1;
    for (int i = 0; i < length; i++)
    {
        if (isspace(text[i]))
        {
            wordCount++;
        }
    }
    return wordCount;
}

// return sentences
int sentences(string text)
{
    int textLength = strlen(text);
    int sentenceCount = 0;
    for (int i = 0; i < textLength; i++)
    {
        int ch = text[i];
        int ex = '!'; // int because characters read as ascii?
        int qu = '?';
        int pe = '.';
        if (ch == pe || ch == ex || ch == qu)
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}

// Might come back to this later
// return index
// int index3(int letters2, int sentences2, int words2)
// {
//     float l = letters2 / words2 * 100;
//     printf("l %f\n", l);
//     float s = sentences2 / words2 * 100;
//     printf("s %f\n", s);
//     float index2 = 0.0;
//     index2 = 0.0588 * l - 0.296 * s - 15.8;
//     int rounded = round(index2);
//     printf("output %d\n" ,rounded);
// }

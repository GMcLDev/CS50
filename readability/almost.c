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
//int index3(int letters2, int sentences2, int words2);

// main
int main(void)
{
    string text = get_string("Enter text: \n");
    float words2 = words(text); // words
    float sentences2 = sentences(text) ; // sentences
    float letters2 = letters(text); // characters
    float l = letters2 / words2 * 100;
    //printf("l %f\n", l);
    float s = sentences2 / words2 * 100;
    //printf("s %f\n", s);
    float index2 = 0.0;
    index2 = 0.0588 * l - 0.296 * s - 15.8;
    int rounded = round(index2);
    if(rounded >= 16)
    {
         printf("Grade: 16+\n");
    }
    else
    {
        printf("Grade: %d\n" ,rounded);
    }
    //float output =  index3(letters2, sentences2, words2);
    //printf("index3 %f\n", output);

}

// return letters
int letters(string text)
{
    int length = strlen(text);
    int letterCount = 0;

    for (int i = 0; i < length; i++ )
    {
        if(isalpha(text[i]))
        {
            //printf("isalpha block characters before: %d\n", letterCount);
            letterCount++;
            //printf("isalpha block characters after: %d\n", letterCount);
        }
    }
    return letterCount;
}

// return words
int words(string text)
{
    int length = strlen(text);
    int wordCount = 1;
    for (int i = 0; i < length; i++ )
    {
      if(isspace(text[i]))
        {
            //printf("isspace block wordCount before: %d\n", wordCount);
            wordCount++;
            //printf("isspace block wordCount after: %d\n", wordCount);
        }
    }
    return wordCount;
}

// return sentences
int sentences(string text)
{
    int textLength = strlen(text);
    int sentenceCount = 0;
    for(int i = 0; i < textLength; i++)
    {
        int ch = text[i];
        int ex = '!'; // int because characters read as ascii?
        int qu = '?';
        int pe = '.';
        if(ch == pe || ch == ex || ch == qu)
        {
            //printf("ch bllock sentences before: %d\n", sentenceCount);
            sentenceCount++;
            //printf("ch sentences after: %d\n", sentenceCount);
        }
    }
    return sentenceCount;
}

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

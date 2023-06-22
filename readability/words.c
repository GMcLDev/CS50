
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text); // , float sentenceCount , float wordCount
int count_sentences(string text);
float index_number(string text, float wordss, float sentencess);

int main(void)
{
    string text = get_string("Enter Text: \n");
    // printf("main block wordCount: %f\n", wordCount);
    int wordss = count_letters(text);
    // printf("main block l: %f\n", l);
    int sentencess = count_sentences(text);
    // printf("main s: %f\n", s);
    index_number(text, wordss, sentencess);
    //printf("Weird number: %f\n", index);
}

int count_letters(string text)
{
    float textLength = strlen(text);
    float wordCount = 0.0;
    float characters = 0.0;
    printf("letters block textLength: %f\n", textLength);
    printf("letters block wordCount before: %f\n", wordCount);
    wordCount += 1;
    printf("letters block wordCount after: %f\n", wordCount);
    for(int i = 0; i < textLength; i++)
    {
        if(isspace(text[i]))
        {
            printf("isspace block wordCount before: %f\n", wordCount);
            wordCount++;
            printf("isspace block wordCount after: %f\n", wordCount);
        }
        if(isalpha(text[i]))
        {
            printf("isspace block characters before: %f\n", characters);
            characters++
            printf("isspace block characters after: %f\n", characters);
        }

    }
    return wordCount;
    // where L is the average number of letters per 100 words in the text,
    // The text the user inputted has 65 letters, 4 sentences, and 14 words.           l = (characters / wordsCount) * 100
    // 65 letters per 14 words is an average of about 464.29 letters per 100 words (because 65 / 14 * 100 = 464.29).
}

int count_sentences(string text) // , float sentenceCount , float wordCount
{
    //  S is the average number of sentences per 100 words in the text.
    //  The text the user inputted has 65 letters, 4 sentences, and 14 words.          s = (sentenceCount / words) * 100
    //  4 sentences per 14 words is an average of about 28.57 sentences per 100 words (because 4 / 14 * 100 = 28.57).

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
            printf("ch bllock sentences before: %d\n", sentenceCount);
            sentenceCount++;
            printf("ch sentences after: %d\n", sentenceCount);
        }
    }
    return sentenceCount;
}

float index_number(string text, float wordss, float sentencess)
{
     int textLength = strlen(text);
     float l = 0;
     printf("l index block before: %f\n", l);
     l = (textLength / wordss) * 100;
     printf("l:  check this!!! index block after %f\n", l);
     printf("index after characters: %d\n", textLength);
     printf("index after sentencess: %f\n", sentencess);

     float s = 0;
     printf("index block sentences before: %f\n", sentencess);
     printf("index block wordsss before: %f\n", wordss);
     s = (sentencess / wordss) * 100;
     printf("index block check this!!! s after: %f\n", s);
     printf("index block sentences after: %f\n", sentencess);

     float index = (0.0588 * l) - (0.296 * s) - 15.8;

     int rounded = round(index);
     printf("index: %d\n", rounded);
     return rounded;
}
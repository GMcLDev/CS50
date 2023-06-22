#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


int count_text(string text);

int main (void)
{
    string text = get_string("Enter text");
    int textCount2 = strlen(text);
    int sentences[textCount2];
    int words[textCount2];
    int characters[textCount2];
    count_text(text);
    for ( int k = 0; k < textCount2; k++)
    {
        printf("Sentences %d\n", sentences[k]);
        printf("words %d\n", words[k]);
        printf("Sentences %d\n", characters[k]);
    }
}

int count_text(string text)
{
    int textLength = strlen(text);
    for (int i = 0 ; i < textLength ; i++)
    {
        char word = text[i];
        int wordLength = strlen(word);
        for (int j = 0; j < wordLength; j++)
        {
            if (words[i] == "!")
            {
                sentences[i] += 1;
            }
            while (word[i] != "\0")
            {
                 chracters[i] += 1;
            }
            words[i] += characters[i];

        }
    }
}
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


int count_text(string text);

int main (void)
{
    string text = get_string("Enter text:\n");
    int words = 0;
    int characters = 0;
    int length = strlen(text);
    int sentencecount = 0;
    int sentences[sentencecount];
    int wordcount = 0;
    int wordarray[wordcount];
    printf("text length %d\n", length);


    for (int i = 0; i < length; i++)
    {
        printf("word %c\n", text[i]);

        if(text[i] == '\0')
        {
            wordcount += 1;
            wordarray[i] = characters;
            characters = 0;

        }
        else
            if (!isalnum(text[i]))
            {
                sentencecount += 1;
                sentences[i] = wordarray[i];
                wordcount = 0;

            }
        else
        {
            characters += 1;
        }
    }

     for ( int k = 0; k < length; k++)
    {
        printf("Sentences %d\n", sentences[k]);
        printf("words %d\n", wordarray[k]);
        // printf("Sentences %d\n", characters[k]);
    }
}





string usertext = get_String("Enter Text\n")
int length2 = strlen(usertext);
int character = 0; // store amount of characters per word
int words = 0; // stores words in sentence
int sentences = 0; // stores amount of sentences
int wordsarray[words]; // an array of amount of characters per word for the number of words in text
int sentencearray[sentences]; // an array of amount of words per sentence for the number of sentences in text


if (character == '!' || character == '.') // checks if end of sentence
{
    sentencearray[index] = words[index]
    sentences++
    characters = 0
}
else if (chracter == '\0') // checks if end of word
{
    wordsarray[index] += characters; // (chars in word)
    words++;
    characters = 0; // reset characters of next word
}
else if (isalpha(character)) // if character is alphabetical add 1 to characters
{
    chracters++;
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    char alphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char lalphabet[26] = {"abcdefghijklmnopqrstuvwxyz"};


    // Chcecks if argv[1] exists
    if (argc < 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // sets argv[1] to key
    string key = argv[1];

    // Checks if >1 command line arguments
    if (argc > 2)
    {
        printf("Too many command line arguments.\n");
        return 1;
    }

    // Checks if length of key is correct
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Checks if each character is a letter and for duplicates if letter
    for (int i = 0; i < 26; i++)
    {
        // changes lower case to upper case so can check plaintext later
        if (islower(key[i]))
        {
            key[i] = toupper(key[i]);
        }
        int dup = 0;

        if (!isalpha(key[i]))
        {
            printf("Key must contain 26 letters.\n");
            return 1;
        }

        for (int j = 0; j < 26; j++)
        {
            char a = key[i];
            char b = key[j];
            if (b == a)
            {
                dup++;
                if (dup > 1)
                {
                    printf("Duplicate Letter\n");
                    return 1;
                }
            }
        }
    }

    // code to cipher
    string plaintext = get_string("plaintext: ");


    // finds letters from plain text
    char ciphert[strlen(plaintext)];
    printf("ciphertext: ");
    int c = 0;

    for (int k = 0; k < strlen(plaintext); k ++)
    {
        for (int l = 0; l < 26; l++)
        {
            char p = plaintext[k]; // letter we want to cipher
            char al = key[l]; // cipher key

            // if lowercase cast cipher to lowercase and print lowercase
            if (islower(plaintext[k]))
            {
                char lal = tolower(key[l]); 
                if (p == lal)
                {
                    c = p - 'a'; // gets index of lowercase alphabet
                    printf("%c", tolower(key[c]));
                }
            }
            else if (p == al)
            {
                c = p - 'A'; // gets index of uppercase alphabet
                printf("%c", key[c]);
            }
        }
        // prints non-alphaetical characters
        if (!isalpha(plaintext[k]))
        {
            printf("%c", plaintext[k]);
        }
    }
    printf("\n");
}


#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Function declearation
int replace(int y, string argv[]);

// Main
int main(int argc, string argv[])
{
    string sentence;
    replace(argc, argv);
}

// Vowel Replacement Function
int replace(int y, string argv[])
{
    // Check if command line argument made, could also use \0?
    if (argv[1] != NULL)
    {
        // itterate y(argc; the amount of CL arguments)
        for (int k = 1; k < y; k++)
        {
            // Length of word
            int length = strlen(argv[k]);

            // Iterate chars in word
            for (int j = 0; j < length; j++)
            {
                // Check each char
                switch (argv[k][j])
                {
                // Swapsies
                case 'a':
                    argv[k][j] = '6';
                    break;
                case 'e':
                    argv[k][j] = '3';
                    break;
                case 'i':
                    argv[k][j] = '1';
                    break;
                case 'o':
                    argv[k][j] = '0';
                    break;
                }
            }
        }
    }
    // return error of no(0) CL arguments
    else
    {
        return 1;
    }

    // Print converted word
    printf("%s\n", argv[1]);

    // Return no errors
    return 0;
}
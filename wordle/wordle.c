#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

// user-defined function prototypes
string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

int main(int argc, string argv[])
{
    // ensure proper usage
    // TODO #1

    int wordsize = 0;

    if (argv[1] != NULL)
    {
        if (strlen(argv[1]) > 1 || argc > 2)
        {
            printf("Error: wordsize must be either 5, 6, 7, or 8\n");
            return 1;
        }
    }
    if (argv[1] == NULL)
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
        return 1;
    }

    // ensure argv[1] is either 5, 6, 7, or 8 and store that value in wordsize instead
    // TODO #2

    if (argv[1][0] < 53 || argv[1][0] > 56)
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
        return 1;
    }
    else
    {
        wordsize = argv[1][0] - 48; // convert AASCII to int value manually
    }

    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];


    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN"This is WORDLE50"RESET"\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    int guesscount = 0; // this is to track gueeses for TODO 7

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // track guesses
        guesscount++;

        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // set all elements of status array initially to 0, aka WRONG
        // TODO #4
        for (int k = 0; k < wordsize; k++)
        {
            status[k] = 0;
        }

        // Calculate score for the guess
        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);

        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    // Print the game's result
    // TODO #7

    if (won == true)
    {
        printf("You won!\n");
    }
    if (guesscount == guesses && won == false)
    {
        printf("You lost! The word was: %s\n", choice);
    }

    // that's all folks!
    return 0;
}

string get_guess(int wordsize)
{
    string guess = "";

    // ensure users actually provide a guess that is the correct length
    // TODO #3

    do
    {
        guess = get_string("Input a %i-letter word:", wordsize);

    }
    while (strlen(guess) != wordsize);

    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    int score = 0;
    // compare guess to choice and score points as appropriate, storing points in status
    // TODO #5

    // HINTS
    for (int l = 0; l < wordsize; l++)
    {
        for (int m = 0; m < wordsize; m++)
        {
            if (guess[l] == choice[m])
            {
                if (l == m)
                {
                    status[l] = 2;
                    score += 2;
                    break;
                }
                else
                {
                    status[l] = 1;
                    score += 1;
                }
            }
        }
    }
    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    // print word character-for-character with correct color coding, then reset terminal font to normal
    // TODO #6

    for (int n = 0; n < wordsize; n++)
    {
        if (status[n] == 2)
        {
            printf(GREEN"%c"RESET, guess[n]);
        }
        else if (status[n] == 1)
        {
            printf(YELLOW"%c"RESET, guess[n]);
        }
        else if (status[n] == 0)
        {
            printf(RED"%c"RESET, guess[n]);
        }
    }

    printf("\n");
    return;
}

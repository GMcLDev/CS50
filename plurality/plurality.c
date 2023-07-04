#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        printf("name: %s\n", candidates[i].name);
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Checks if name paremter is empty
    if (name == NULL || (strcmp(name,  " ") == 0))
    {
        return false;
    }
    // Iterates over names if candidate name isn't empty, then compares it to name parameter and updates votes
    for (int j = 0; j < candidate_count; j++) // max
    {
        if (candidates[j].name != NULL && strcmp(name, candidates[j].name) == 0)
        {
            //printf("found");
            candidates[j].votes += 1;
            return true;
        }
    }
    return false;
}



// Print the winner (or winners) of the election
void print_winner(void)
{
    int max = 0; // Tracks max votes
    int winners = 0; // Tracks number of winners

    // Sets max to highest number of votes
    for (int l = 0; l < candidate_count; l++)
    {
        if (candidates[l].votes > max)
        {
            max = candidates[l].votes;
        }
    }
    // If multiple candidates votes == max track how many
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max)
        {
            winners++;
        }
    }

    // Array to store names of winners
    string winner[winners];
    int winner_index = 0; // To store winners in correct index of winner array

    // If candidates votes == max insert name into array
    for (int m = 0; m < candidate_count; m ++)
    {
        if (candidates[m].votes == max)
        {
            winner[winner_index] = candidates[m].name;
            winner_index++;
        }
    }

    // if more than one candidate has max votes print from winner array
    if (winners > 1)
    {
        for (int k = 0; k < winners; k ++)
        {
            printf("%s\n", winner[k]);
        }
    }
    else // if one winner print first index of array
    {
        printf("%s\n", winner[0]);
    }
}
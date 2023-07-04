#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

// Max number of candidates
#define MAX 9

// preference [i][j] is number of voters who prefer i over j
int preferences[MAX][MAX]; // [candidate 0][candidate 0] skip
                           // [candidate 0][candidate 1]
                           // [candidate 0][candidate 2]

                           // [candidate 1][candidate 0]
                           // [candidate 1][candidate 1] skip
                           // [candidate 1][candidate 2]

                           // [candidate 2][candidate 2]
                           // [candidate 2][candidate 1]
                           // [candidate 2][candidate 2] skip


// locked[i][j] means i is locked in over j || i > j
bool locked[MAX][MAX];

// each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2]; // 36

int pair_count;
int candidate_count;

// Function protottypes
bool vote(int rank, string name, int ranks[]);
// void record_preferences(int ranks[]);
// void add_pairs(void);
// void sort_pairs(void);
// void lock_pairs(void);
//void print_winners(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc -1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    // Populate names
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked pairs
    // for (int i = 0; candidate_count; i++)
    // {
    //     for (int j = 0; j < candidate_count; j++)
    //     {
    //         locked[i][j] = false;
    //     }
    // }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each week
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks)) // if returns false
            {
                printf("Invalid vote. \n");
                return 3;
            }
        }

        //record_preferences(ranks);

        printf("\n");
    }

    // add_pairs();
    // sort_pairs();
    // lock_pairs();
    // print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // check if input is null
    if (name == NULL)
    {
        return 1;
    }
    // check if name in candidates
    int matches = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if((strcmp(name, candidates[i]) == 0))
        {
            matches++;
        }
    }
    if (matches == 0)
    {
        return false;
    }

    // for amount of candidates
    // track index(rank)
    rank = 0;
    for (int j = 0; j < candidate_count; j++)
    {
        printf("j %i\n", j);
        if (strcmp(name, candidates[j]) == 0)  // if name matches candidate
        {
            ranks[j] = rank; // update ranks[i] with rank
            printf("name %s, candidates[j] %s, ranks[j] %i, rank %i\n", name, candidates[j], ranks[j], rank);
            rank++; // move on to next rank = ++
            printf("\n");
            printf("after name %s, candidates[j] %s, ranks[j] %i, rank %i\n", name, candidates[j], ranks[j], rank);
        }
    }

    return true;
}

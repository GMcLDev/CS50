#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool cycle(int winner, int loser);
void print_winner(void);



int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{

    if (name == NULL)
    {
        return false;
    }
    // check if name in candidates
    int matches = 0;
    for (int l = 0; l < candidate_count; l++)
    {
        if ((strcmp(name, candidates[l]) == 0))
        {
            matches++;
        }
    }
    // if vote (name) not in candidates exit
    if (matches == 0)
    {
        return false;
    }

    // rank == j == vote number. 0 = first preference, 1 second etc.
    for (int m = 0; m < candidate_count; m++)
    {
        for (int k = 0; k < candidate_count; k++)
        {
            if (strcmp(name, candidates[k]) == 0)
            {
                ranks[rank] = k;
            }
        }
    }
    return true;
}


// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++) // skips comparing same candidate
        {
            preferences[ranks[i]][ranks[j]] += 1; // for each vote candidate[i] vs candidate[j] where i is preferred over j, +1 vote
        }
    }
    return;
}


// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++) // skips i == j alice alice etc
        {
            if (preferences[i][j] > preferences[j][i] && preferences[i][j] > 0)
            {
                // if [i] wins over [j] and a preference was recorded add winner/loser pair to pairs
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j] && preferences[j][i] > 0)
            {
                // if [j] wins over [i] and a preference was recorded add winner/loser pair to pairs
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }

    //printf("pair_count %i\n", pair_count);

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1 ; j < candidate_count; j++) // skip same candidate
        {
            if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[j].winner][pairs[j].loser])
            {
                // sort in descending order of strength of victory where [i] recieved more votes over [j] than another pair
                int tempwin = pairs[i].winner;
                int templos = pairs[i].loser;

                pairs[i].winner = pairs[j].winner;
                pairs[i].loser = pairs[j].loser;

                pairs[j].winner = tempwin;
                pairs[j].loser = templos;
            }
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{

    // Traverse pairs array
    for (int i = 0; i < pair_count; i++)
    {
        if (!cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}
bool cycle(int winner, int loser)
{
    if (locked[loser][winner])
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i] && cycle(winner, i))
        {
            return true;
        }
    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool edge_finder = false;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true) // if and edge TO the candidate exists they cannot be source
            {
                edge_finder = true;
                break;
            }
        }
        if (edge_finder == true) // if edge found move to next candidate
        {
            continue;
        }
        else if (edge_finder == false) // must be source if no edges found
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
    return;
}




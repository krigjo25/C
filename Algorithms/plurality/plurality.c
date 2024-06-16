/*******************************************************************************
    Title : Pularity
    Description : Implements a CS program to simulate a voting as Pularity
    Base by : CS50, Problem set 02
    Developed by : @krigjo25

******************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Define a structure called Candidates to store name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Declare number of candidates
int candidate_count;

// Declare Prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Ensure the program is not invalid
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;

    // Ensure there are maximum allowed candidates
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    //  Looping through candiates
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    //  Promting the user for an integer
    int voter_count = get_int("Number of voters: ");

    // Calculating voters
    for (int i = 0; i < voter_count; i++)
    {
        //  Promting the user for candate name
        string name = get_string("Vote: ");

        // Ensure the vote is valid
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

    // Search after Candidate
    for (int i = 0; i < MAX; i++)
    {
        //  Matching candidates
        int result = strcmp(name, candidates[i].name);

        //  Ensure the name matches
        if (result == 0)
        {
            //  Increasing the votes for the candidate
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //  Initializing a max value
    int max = candidates[0].votes;

    //  Linear search for the candidate with max votes
    for (int i = 0; i < sizeof(candidate); i++)
    {
        //  Ensure the candidate has a greater vote than previous candidate
        if (candidates[i].votes > max)
        {
            //  Swap to the highest count
            max = candidates[i].votes;
        }
    }

    //  Selection sort algorithm to sort the candidates
    for (int i = 0; i < sizeof(candidate); i++)
    {
        //  Ensure the candidate has the total vote
        if (candidates[i].votes == max)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}

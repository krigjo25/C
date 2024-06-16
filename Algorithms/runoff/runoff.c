/*******************************************************************************
    Title : Runoff
    Description : A CS program to simulate a run off election
    Base by : CS50, Problem set 03
    Developed by : @krigjo25

******************************************************************************/

//  Import responsories
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Define voters and candidates limits
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

//  Defining a structure to keep name, vote count, eliminated status for candidates
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Declare an Array of candidates
candidate candidates[MAX_CANDIDATES];

// Declare number of voters, number of candidates
int voter_count;
int candidate_count;

// Declare Prototypes
int find_min(void);
void tabulate(void);
bool is_tie(int min);
void eliminate(int min);
bool print_winner(void);
bool vote(int voter, int rank, string name);

int main(int argc, string argv[])
{
    // Ensure the usage is not invalid
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Initialize number of candidates
    candidate_count = argc - 1;

    //  Ensure number of candidates does not exceed the Max number of candidates
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    //  Loop through the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    //  Promt the user for integers
    voter_count = get_int("Number of voters: ");

    //  Ensure the voters does not exceed the limit
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Ensure the vote is valid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    //  Ensure the program continues untill a candidate wins
    while (true)
    {
        //  Calculate votes given remaining candidates
        tabulate();

        // Ensure that someone won the runoff
        bool won = print_winner();
        if (won)
        {
            break;
        }

        //  Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        //  Ensure that everyone wins if case is tied
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset votes
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid *
bool vote(int voter, int rank, string name)
{
    // Looping through the counted voter
    for (int i = 0; i < candidate_count; i++)
    {

        //  Regular expression to ensure name and candidate match
        int match = strcmp(name, candidates[i].name);

        // Ensure the match
        if (match == 0)
        {
            //  Update preferences
            preferences[voter][rank] = i;
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates *
void tabulate(void)
{
    // looping through every voter
    for (int i = 0; i < voter_count; i++)
    {
        // looping through every candidate
        for (int j = 0; j < candidate_count; j++)
        {
            // Ensure candidate is not already eliminated
            if (candidates[j].eliminated == false)
            {
                // append a vote to the candidate
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Looping through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Ensuring that the candidate has atleast 51% of votes
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has *
int find_min(void)
{
    //  Initializing minimal variable
    int min = 0;

    // Looping through every candidate
    for (int i = 0; i < candidate_count; i++)
    {
        //  Ensuring the candidate is not eliminated and ensuring the candidate's vote is greater
        //  than min value
        if (candidates[i].eliminated != true && candidates[i].votes > min)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise *
bool is_tie(int min)
{
    //  Initializing variables
    int eliminated = 0;

    // Looping through every candidate
    for (int i = 0; i < candidate_count; i++)
    {
        //  Ensure candidate is eliminated, then count as eliminated
        if (candidates[i].eliminated == true)
        {
            eliminated += 1;
        }
    }
    //  Ensure 2 of 3 candidates is eliminated
    if (eliminated < candidate_count / 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void eliminate(int min)
{
    /*
        Eliminate the candidate (or candidates) with minimum votes.
    */

    //  Looping through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //  Ensure the candidates vote is the minimum
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}

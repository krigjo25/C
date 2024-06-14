/*******************************************************************************
    Title : scrabbles
    Description : Simulates blocks such in mario.
    Base by : CS50, Problem set 03
    Developed by : @krigjo25
    Date Started : January, 2023
    Date Submited : Tuesday, January 10, 2023 3:14 PM CET

******************************************************************************/
//  Import responsories
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score[] = {compute_score(word1), compute_score(word2)};

    //  Print the winner
    if (score[0] > score[1])
    {
        printf("Player 1 wins!\n");
    }

    else if (score[0] < score[1])
    {
        printf("Player 2 wins!\n");
    }

    else
    {
        printf("Tie !\n");
    }
}

int compute_score(string word)
{
    /*
        #   Prompts the words for each player
        #   Calculating the score for both words
        #   Returing score from string

    */

    //  Initialize variables
    int result = 0;

    //  Iteration over the length of the alphabeth
    for (int i = 0; i < strlen(word); i++)
    {

        for (int j = 0; j < strlen(word); j++)
        {
            //  Converting to lower case letters
            word[j] = tolower(word[j]);

            //  Checking if the letter is in list
            if (word[j] == word[i])
            {
                //  Adding points to the result
                result += POINTS[i];
            }
        }
    }

    return result;
}

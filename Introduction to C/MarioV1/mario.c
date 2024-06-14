/*******************************************************************************
    Title : mario blocks
    Description : Simulates blocks such in mario.
    Base by : CS50, Problem set 02
    Developed by : @krigjo25
    Date Started : Wedensday, January 4, 2023
    Date Submited :  Wednesday, January 4, 2023 5:18 PM CET

******************************************************************************/

//  importing libraries
#include <cs50.h>
#include <stdio.h>

// Prototypes
void Pyramid(void);

int main(void)
{

    // Call Pyramid
    Pyramid();
}

// Version one with do while
void Pyramid(void)
{
    //  Declareing variables
    int prompt;

    //  Prompt user before check
    do
    {
        //  Initializing variables
        prompt = get_int("Height : ");
    }

    while (prompt < 1 || prompt > 8);

    //  Creating Rows
    for (int i = 0; i < prompt; i++)
    {
        // Creating Space columns
        for (int j = prompt - 1; j > i; j--)
        {
            printf(" ");
        }

        // Print out Hashes
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        // Newline
        printf("\n");
    }
}

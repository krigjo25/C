/*******************************************************************************
    Title : mario blocks
    Description : Simulates blocks such in mario.
    Base by : CS50, Problem set 02
    Developed by : @krigjo25
    Date Started : February 09, 2023
    Date Submited : N/A
    Date re-Submited : N/A

******************************************************************************/
//  Include libraries
#include <cs50.h>
#include <stdio.h>

void Pyramid(void);

int main(void)
{
   Pyramid();

}

void Pyramid(void)
{
    /*
      #   Developed by :        @krigjo25
      #   Date :                09.02-23

      #   Creating 'blocks' from the user input
      #   using Do While, adding dots for each step
    */

    //  Declare variables
    int n;
    do
    {

      // Initializing variable
      n = get_int("Blocks : ");
    }

    while (n < 1 || n > 8);

      //  Counting rows
      for (int i = 1; i <= n; i++)
      {

        // Counting space
        for (int j = n; j > i ; j--)
        {
          printf(" ");
        }

        //  Counting hashes on the right side
        for (int k = 0; k < i; k++)
        {
          printf("#");
        }

        //  Print space
        for (int l = 0; l < 2; l++)
        {
          printf(" ");
        }

        //  Counting hashes on the left side
        for (int m = 0; m < i; m++)
        {
          printf("#");
        }

        //  New row
        printf("\n");
      }
}
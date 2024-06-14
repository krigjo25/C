/*******************************************************************************
    Title : Population
    Description : Simulates population growth over time.
    Base by : CS50, Problem set 02
    Developed by : @krigjo25
    Date Started : Wedensday January 04, 2023
    Date Submited : Wednesday, January 4, 2023 8:54 AM CET
    Date re-Submited : N/A

******************************************************************************/

// Including libraries
#include <stdio.h>
#include <cs50.h>
#include <math.h>

//  Declare functions
void Population(void);

int main(void)
{
    // Calling Population
    Population();
}

void Population(void)
{
    /*
        #   Prompts the user for a starting population size. If the number is less than 9  the user will be re
        #   If the user's input is less than 9, the user will be re-prompted to enter a new number untill the number is greater than or equal to 9.
        #   The Population function prompts the user for ending population size.
        #   If the user enters a number less than the starting population size, the program re-prompts the user to enter an ending population size until the number is greater than or equal to the starting population.
        #   The program calculates the (integer) number of years required for the population to reach at least the size of the end value.
        #   Finally, the program prints the number of years required for the llama population to reach that end size, as by printing to the terminal Years: n, where n is the number of years.

        #   The Math formula
        #  n += round(n/3 - n/4)
    */

    //  Declareing variables
    int n;
    int end;
    int counter = 0;

    //  Does something before conditon check
    do
    {
        // Prompting the user for N population
        n = get_int("Start population: ");
    }
    while (n < 9);

    do
    {
        // Prompting the user for end population
        end = get_int("End Population: ");
    }

    while (end < n);

    // Calculating how many years it will take to reach the end population
    // Calculating how the population grows with-in one year

    while (n < end)
    {
        // Increases by 3 and decreases by 4
        n += ceil((n / 3 - n / 4));

        //  Counting the years
        counter++;
    }


    //  Outputs the results
    printf("Years: %d", counter);
}
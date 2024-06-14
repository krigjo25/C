/*******************************************************************************
    Title : Hours
    Description : Implement the functionallity of calc_hours
    Base by : CS50, Problem set 01
******************************************************************************/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//  Prototype
float calc_hours(int hours[], int weeks, char output);

int main(void)
{

    // Prompt the user for an integer
    int weeks = get_int("Number of weeks taking CS50: ");

    //  Initialize variables
    char output;
    int hours[weeks];

    // Iterating over the prompted message
    for (int i = 0; i < weeks; i++)
    {
        // appending to the list
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    do
    {
        // Prompt the user for an char
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    // Print out the output
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
    return 0;
}

// Calculates hours
float calc_hours(int hours[], int weeks, char output)
{
    // Initialize variable
    float total = 0;

    //  Iterating over the array
    for (int i = 0; i < weeks; i++)
    {
        total += hours[i];
    }

    // Comparing the outputted message
    if (output == 65)
    {
        return total / weeks;
    }

    else if (output == 84)
    {
        return total;
    }
    return 0;
}

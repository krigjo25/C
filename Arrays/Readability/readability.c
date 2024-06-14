/*******************************************************************************
    Title : Readability
    Description :   Implements a CS program to calculate the avg reading rate,
                    by using the formula of Coleman Liau.

    Base by : CS50, Problem set 02
    Developed by : @krigjo25
    Date Started : Tuesday, January 10, 2023
    Date Submited : Wednesday, January 11, 2023 11:56 AM CET

******************************************************************************/
//  importing  libraries
#include <math.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//  Declare Functions
int countingwords(string arg);
int countingletters(string arg);
int countingsentences(string arg);
int coleman_liau_formula(string arg);

int main(void)
{
    //  Prompts the user for a string.
    string s = get_string("Calculate sentence: ");

    //  Checking if the string was read
    if (s == NULL)
    {
        return 1;
    }
    return coleman_liau_formula(s);
}

int countingletters(string arg)
{

    //  Initializing a variable called counter
    int counter = 0;

    //  Iterating through the string
    for (int i = 0; i < strlen(arg); i++)
    {
        //  Ensuring the condtion is met
        if (isalpha(arg[i]))
        {
            //  Counting letters
            counter++;
        }
    }

    return counter;
}

int countingwords(string arg)
{
    //  Initializing a variable called counter
    int counter = 1;

    //  Iterating through the string
    for (int i = 0; i < strlen(arg); i++)
    {
        //  Checking if the condition is met
        if (isspace(arg[i]))
        {
            //  Counting words
            counter++;
        }
    }

    return counter;
}

int countingsentences(string arg)
{
    //  Initializing a variable called counter
    int counter = 0;

    //  Initializing arrays
    int symbols[3] = {33, 46, 63};

    //  Iterating through the string
    for (int i = 0; i < strlen(arg); i++)
    {
        //    Checks if the ACII value is above 90
        //    Checks if the argument contains one of the symbols
        for (int j = 0; j < 3; j++)
        {
            if (arg[i] == symbols[j])
            {
                counter++;
            }
        }
    }

    return counter;
}

int coleman_liau_formula(string arg)
{

    // Initializing variables
    float l = countingletters(arg);
    int w = countingwords(arg);
    float s = countingsentences(arg);

    //   Calculating the Letters
    l = (l / w) * 100;

    //   Calculating the Sentence
    s = (s / w) * 100;

    //  Coleman-Liau Formula
    int cli = round((0.0588 * l) - (0.296 * s) - 15.8);

    // Ensuring conditions and prints out result
    if (cli < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (cli > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", cli);
    }
    return 0;
}

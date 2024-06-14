/*******************************************************************************
    Title : Bulbs
    Description :
                    #   Simulates light blocks.
                    #   Missing 1 zero

    Base by : CS50, Problem set 03
    Developed by : @krigjo25
    Date Started : March, 2023
    Date Submited : Monday, March 27, 2023 7:11 PM CET
    Date re-Submited : N/A

******************************************************************************/

//  Importing responsories
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

//  Initialize Prototypes
void print_bulb(int bit);
void DecimalToBinary(int n);

int main(void)
{
    //  Prompting the user for input
    string prompt = get_string("Convert your sentence :");

    //  Iterate over the prompted word
    for (int i = 0; i < strlen(prompt); i++)
    {
        DecimalToBinary(prompt[i]);
        printf("\n");
    }
    return 0;
}

//  Converting Binary
void DecimalToBinary(int n)
{
    if (n > 0)
    {
        DecimalToBinary(n / 2);
    }
    return print_bulb(n % 10);
}

//  Prints out the results
void print_bulb(int bit)
{

    if (bit == 0)
    {
        printf("\U000026AB"); // Dark emoji
    }
    else if (bit == 1)
    {
        printf("\U0001F7E1"); // Light emoji
    }
}

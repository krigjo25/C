/*******************************************************************************
    Title : Hello
    Description : Implements the functionallity to print a prompted string.
    Base by : CS50, Problem set 02
    Developed by : @krigjo25
    Date Started : Wedensday, January 4, 2023
    Date Submited : Wednesday, January 4, 2023 9:06 AM CET

******************************************************************************/
//  Including libraries
#include <stdio.h>
#include <cs50.h>


int main(void)

{
    //  Fetch the user name
    string name = get_string("What's your name?");

    //  Print the string
    printf("hello, %s\n", name);
}

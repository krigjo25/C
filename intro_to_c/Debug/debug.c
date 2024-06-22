/*******************************************************************

    Title : Debug
    Developed by : @krigjo25
    Date stamp :
    Description : A program to be familiar with C syntax and debug a buggy code
*******************************************************************/

//  import responsories
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // fetch user input
    string name = get_string("What is your name? ");
    string location = get_string("Where do you live? ");

    //  Print out message
    printf("Hello, %s, from %s!", name, location);
}

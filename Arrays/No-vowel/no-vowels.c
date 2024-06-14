/*******************************************************************************
    Title : n0-V0v3l
    Description : A functionallity to replace leters with numbers
    Base by : CS50, Problem set 01
******************************************************************************/

// Import responsories
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string arr[]); // Declare a new function

int main(int argc, string argv[])
{

    //  Ensure the Command-line argument not equals 2
    if (argc != 2)
    {
        printf("Useage ./novowels word\n");
        return 1;
    }
    else
    {
        replace(argv);
    }
    return 0;
}

string replace(string arr[])
{
    // iterate over an array
    for (int i = 0; i < strlen(arr[1]); i++)
    {
        //  Ensure the condition is met
        switch (arr[1][i])
        {
            case 'a':
                arr[1][i] = '6';
                break;

            case 'e':
                arr[1][i] = '3';
                break;

            case 'i':
                arr[1][i] = '1';
                break;

            case 'o':
                arr[1][i] = '0';
                break;

        }

    }

    printf("%s\n", arr[1]);
    return 0;
}

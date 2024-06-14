/*******************************************************************************
    Title : Password
    Description : Checking if the password is secure
    Base by : CS50, Problem set 01
******************************************************************************/

// Import responsories
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//  Prototypes
bool valid(string password);

int main(void)
{
    // Prompting the user for a string
    string password = get_string("Enter your password: ");

    // Ensure the password is valid
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }

    //  Otherwise notify the user its incorrectly used
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

bool valid(string password)
{
    //  Initializing variables
    bool sym = false;
    bool num = false;
    bool up = false;
    bool low = false;


    //  Looping over condtions
    for (int i = 0; i < strlen(password); i++)
    {

        if (isupper(password[i]))
        {
            up = true;
        }
        else if (islower(password[i]))
        {
            low = true;
        }
        else if (isdigit(password[i]))
        {
            num = true;
        }
        else if (isgraph(password[i]))
        {
            sym = true;
        }
    }

    //  Ensuring the correct boolean values
    if (num == true && sym == true && up == true && low == true)
    {
        return true;
    }

    return false;
}

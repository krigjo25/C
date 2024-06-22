/*******************************************************************************
    Title : Cash
    Description : Implements the functionallity for automated cash back.
    Developed by : @krigjo25
    Date Started : January, 2023
    Date Submited : Saturday, January 7, 2023 10:58 AM CET
    Date re-Submited : N/A

******************************************************************************/
//  Import responsories
#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt the costumer for cents owed
    int cents = get_cents(); 

    //  Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    int coins = quarters + dimes + nickels + pennies; // Sum coins


    printf("%i\n", coins); // Print total number of coins to give the customer
}

int get_cents(void)
{
    //  Declare variable cent
    int cents;

    do
    {
        //  Prompting the user for cents
        cents = get_int("How many number of cents :");
    }

    while (cents < 0);

    return cents;
}

int calculate_quarters(int cents)
{
    /*
        #   Math Exercise
        #   1 Quarter == 25 cents
        #   25 / 25 = 1 Quarter

    */

    //   Initializing variables
    int c = 0;

    while (cents >= 25)
    {

        //   Increase cash, decrease cents
        c++;
        cents -= 25;
    }

    return c;
}

int calculate_dimes(int cents)
{
    /*
        #   Math Exercise
        #   1 Dime == 10 cents
        #   25 / 25 = 1 Dime

    */

    //   Initializing variables
    int c = 0;

    while (cents >= 10)
    {

        //   Increase cash, decrease cents
        c++;
        cents -= 10;
    }

    return c;
}

int calculate_nickels(int cents)
{
    /*
        #   Math Exercise
        #   1 Nickel == 5 cents
        #   5 / 5 = 1 Nickle

    */

    //   Initializing variables
    int c = 0;

    while (cents >= 5)
    {

        //   Increase cash, decrease cents
        c++;
        cents -= 5;
    }

    return c;
}

int calculate_pennies(int cents)
{

    /*
        #   Math Exercise
        #   1 Pennie == 1 cents
        #   1 / 1 = 1 Pennie

    */

    //   Initializing variables
    int c = 0;

    while (cents >= 1)
    {

        //   Increase cash, decrease cents
        c++;
        cents -= 1;
    }

    return c;
}

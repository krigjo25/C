/************************************************************
        Developed by : @krigjo25
        Date : 02-23

        #   Prompting the user for an input.
        #   Assign the inputed value into a array
        #   Using the algorithm of luhn, also called modulo algortihm

**************************************************************/
//   Importing responsories
#include <cs50.h>
#include <stdio.h>

#define BIN_LENGTH 4

int main(void)
{

    // Declare variables
    long n;
    long q;

    // Initializing the length variable
    int __length = 0;

    // Prompt the user for itegers as long the length is less than 12
    do
    {
        //    Initialize the variable
        __length = 0;

        //  Ensure the length is less than 12
        if (__length < 12)
        {
            // Prompt the user for an input
            n = get_long("Credit Card Number :");

            //  Point to this variable.
            q = n;
        }

        //  Fetching the length of the input
        do
        {
            //  Divide the promted integer with 10
            q /= 10;

            // increase array length
            __length++;
        }

        while (q != 0);

        //  Ensure the length is less than twelve
        if (__length < 12)
        {
            //  When the length is less than twelve we are sure it's not a credit card
            printf("INVALID\n");
            return 0;
        }
        //  When the length is greater than 19 we are sure it's not a credit card       else if
        //  (__length > 19)
        {
            printf("INVALID\n");
        }
    }

    while (__length < 12); // END

    //  Pointer to n
    long r = n;

    //  Array decleration
    int array[__length];

    // Looping through the length of __length
    for (int i = 0; i < __length; i++)
    {
        // appending integers into array

        // Reminder of n
        int mod = r % 10;

        // append to array
        array[i] = mod;

        //  Now we divide the reminders with 10
        r = r / 10;
    }

    //  Bank Identification number
    int BIN[BIN_LENGTH];
    int k = 0;

    //  Looping through the bin
    for (int i = __length; i >= __length - BIN_LENGTH; i--)
    {
        BIN[k] = array[i];
        k++;
    }

    //  Luhn algorithm / modulo algorithm
    //  Looping through every even numbers
    for (int i = 1; i < __length; i += 2)
    {
        //  multiply by 2
        array[i] *= 2;

        if (array[i] > 9) //  multiply by 2
        {
            //  array pointer
            int counter = array[i];
            int integer = 0;

            while (counter != 0)
            {
                int mod = counter % 10;
                integer += mod;

                //  Divide n with 10
                counter /= 10;
            }
            // append to array
            array[i] = integer;
        }
    }

    int sum = 0;

    //  Looping through the array
    for (int i = 0; i < __length; i++)
    {
        //  Summing the array
        sum += array[i];
    }

    if (sum % 10 == 0)
    {
        for (int i = 0; i <= BIN_LENGTH; i++)
        {
            printf("%d", BIN[i]);
            if (BIN[i] == 4)
            {
                printf("VISA\n");
                break;
                return 0;
            }

            else
            {
                printf("MASTERCARD\n");
                break;
            }
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

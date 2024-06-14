// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{

    //  Declare variable
    int n;

    do
    {
        //  Prompt the user for an integer
        n = get_int("Number of elements: ");
    }
    while (n < 1); // END

    //  Declare an array
    int arr[n];

    //  Looping through n
    for (int i = 0; i < n; i++)
    {
        //  Initializing the variable
        arr[i] = get_int("Element %i: ", i);
    }

    //  Print out the outcome
    printf("The max value is %i.\n", max(arr, n));
}

int max(int array[], int c)
{
    // Initalize the variable n
    int n = array[0];


    //  Linear alogrithm
    for (int i = 0; i < c; i++)
    {
        //  Ensure n is less than the array
        if (n < array[i])
        {
            //  array[i] must be max value
            n = array[i];
        }
    }
    return n;
}

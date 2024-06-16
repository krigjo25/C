/*******************************************************************

    Title : Half
    Developed by : @krigjo25
    Date stamp :
    Description : A program to Calculate the half of a resturant bill
*******************************************************************/

//  import responsories
#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    //  Initialize variables
    float bill = get_float("Bill before tax and tip: ");
    float tax = get_float("Sale Tax Percent: ");
    int tip = get_int("Tip percent: ");

    //  Print value
    printf(" Bill $%.2f.\nTip : %d.\nTax prercent $%.2f. \nTotal bill : $%.2f", bill, tax, tip, half(bill, tax, tip));
}

float half(float b, float t, int n)
{
    //  Calculating the taxes
    t *= b / 100;

    //  Adding taxes into the bill
    b += t;

    //  Calculating the tip
    float n = n * b / 100.0;

    //  Adding the tip into the bill
    b += n;
    b /= 2;

    //  Returing the result
    return b;
}

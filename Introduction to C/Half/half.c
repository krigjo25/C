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
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    //  Print value
    printf("$%.2f", half(bill_amount, tax_percent, tip_percent));
}

float half(float bill, float tax, int tip)
{
    //  Calculating the taxes
    tax *= bill / 100;

    //  Adding taxes into the bill
    bill += tax;

    //  Calculating the tip
    float n = tip * bill / 100.0;

    //  Adding the tip into the bill
    bill += n;
    bill /= 2;

    //  Returing the result
    return bill;
}

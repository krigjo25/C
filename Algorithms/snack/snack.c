// Practice using structs
// Practice writing a linear search function

/**
 * Beach Burger Shack has the following 10 items on their menu
 * Burger: $9.5
 * Vegan Burger: $11
 * Hot Dog: $5
 * Cheese Dog: $7
 * Fries: $5
 * Cheese Fries: $6
 * Cold Pressed Juice: $7
 * Cold Brew: $3
 * Water: $2
 * Soda: $2
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Number of menu items
#define MAX_ITEMS 10

//  Define a structure to hold the item and price
typedef struct node
{
    string item;
    float price;
} node;

//  Initializing an Structured array
node menu[MAX_ITEMS];

//  Initializing an array for items
string items[MAX_ITEMS] = {"Fries", "Cheese Fries",
    "Burger", "Hot Dog", "Cheese Dog", "Vegan Burger",
    "Soda", "Water", "Cold Brew", "Cold Pressed Juice"};

//  Initializing an array for the price
float price[MAX_ITEMS] = {5.00, 6.00, 9.50, 5.00, 7.00, 11.00, 2.00, 2.00, 3.00, 7.00};

// Initializing prototypes
void add_items(void);
float get_cost(string item);

int main(void)
{
    //  Adding values to the BBS
    add_items();

    //  Print output
    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    //  Iterating through the menu
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i].price);
    }
    printf("\n");

    float total = 0;

    while (true)
    {
        //  Prompt user for input
        string item = get_string("Enter a food item: ");

        // Ensure the string
        if (strlen(item) == 0)
        {
            printf("\n");
            break;
        }
        //  Calculate total order
        total += get_cost(item);
    }

    printf("Your total cost is: $%.2f\n", total);
}

// Add at least the first for items to the menu array
void add_items(void)
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        // Appending to the Structure
        menu[i].item = items[i];
        menu[i].price = price[i];
    }
    return;
}

// Search through the menu array to find an item's cost
float get_cost(string item)
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (strcmp(menu[i].item, item) == 0)
        {
            printf("%s", menu[i].item);
            return menu[i].price;
        }
    }
    return 0;
}

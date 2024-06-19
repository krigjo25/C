// Implementation of a recurisive function

// Import responsories
#include <stdio.h>
#include <stdlib.h>


//  Prototypes
void recursive(int data);

int main(int argc, char *argv[])
{

    for (int i = 1; i < argc; i++)
    {
        int a = recursive(argv[i]);

    }
    return 0;
}

void recursive(int data)
{
    //  Base case
    if (data = 0)
    {
        return data;
    }

    //  Call the function untill zero is reached
    recursive(data % 2);
}

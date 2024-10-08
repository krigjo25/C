/*******************************************************************************
    Title : Inheritance
    Description : Simulate genetic inheritance of blood type
    Base by : CS50, LAB 06
    Developed by : krigjo25
    Date Started : September, 20, 2023
    Date Submited : September 27, 2023 7:44 PM CEST
    Date re-Submited :

******************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    person *n = malloc(sizeof(person)); // Allocate memory for new person

    if (n == NULL)
    {
        return NULL;
    }

    if (generations > 1) // If there are still generations left to create
    {
        for (int i = 0; i < 2; i++)
        {
            person *parent =
                create_family(generations - 1); // Create two new parents for current person by recursively calling create_family

            n->parents[i] = parent; // Set parent pointers for current person
            n->alleles[i] =
                n->parents[i]
                    ->alleles[rand() % 2]; // TODO: Randomly assign current person's alleles based on the alleles of their parents
        }
    }

    // If there are no generations left to create
    else
    {
        for (int i = 0; i < 2; i++)
        {
            // Set parent pointers to NULL
            n->parents[i] = NULL;

            // Randomly assign alleles
            n->alleles[i] = random_allele();
        }
    }

    // Return newly created person
    return n;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Free parents recursively
    for (int i = 0; i < 2; i++)
    {
        if (p->parents[i] != NULL)
        {
            free_family(p->parents[i]);
        }
    }

    free(p); // Free Child
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}

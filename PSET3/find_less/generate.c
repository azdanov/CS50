/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX], one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include "../../src/cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Ensure there are correct number of arguments provided
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // How many numbers to provide
    int n = atoi(argv[1]);

    // If there is an argument provided, use it, otherwise use current time as seed
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // Print out to console a random number from 0 up to LIMIT.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}

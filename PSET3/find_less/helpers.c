/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n) {

    int mid,
        lower = 0,
        upper = n - 1;

    do {
        mid = (lower + upper) / 2;
        if (value < values[mid])
            upper = mid - 1;
        else if (value > values[mid])
            lower = mid + 1;
        else
            return true;
    } while (mid > 0 && mid < n - 1);

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n) {
    // TODO: implement an O(n^2) sorting algorithm
    return;
}

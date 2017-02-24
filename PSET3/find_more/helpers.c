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

    int mid, lower = 0, upper = n - 1;

    do {
        mid = (lower + upper) / 2;
        if (value < values[mid])
            upper = mid - 1;
        else if (value > values[mid])
            lower = mid + 1;
        else
            return true;
    } while (lower <= upper);

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n) {
    int histogram[LIMIT+1] = {0};

    // Create a histogram of the sorted array
    for (int i = 0; i < n; ++i) {
        ++histogram[values[i]];
    }

    // Sort array
    for (int i = 0, array_iter = 0; i < LIMIT+1; ++i) {
        if (histogram[i]) {
            // Insert j number of values from histogram
            for (int j = 0; j < histogram[i]; ++j, ++array_iter) {
                values[array_iter] = i;
            }
        }
    }
    return;
}

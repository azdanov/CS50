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
 void swap(int *values, int j) {
    int temp = values[j - 1];
    values[j - 1] = values[j];
    values[j] = temp;
}
void sort(int values[], int n) {
    int j;
    for (int i = 1; i < n; ++i) {
        j = i;
        while (j > 0 && values[j - 1] > values[j]) {
            swap(values, j);
            --j;
        }
    }
    return;
}


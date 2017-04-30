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

    int start = 0, end = n - 1, middle;

    while (start <= end) {

        middle = (start + end) / 2;

        if (values[middle] == value) {
            return true;
        }
        else if (values[middle] > value) {
            end = middle - 1;
        }
        else if (values[middle] < value) {
            start = middle + 1;
        }
        else {
            break;
        }
    }
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


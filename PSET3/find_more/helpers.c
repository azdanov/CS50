/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <string.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
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
 * Find max number
 */
int find_max(int array[], int n) {
    int max_num = array[0];

    for (int i = 1; i < n; ++i) {
        if (max_num < array[i]) {
            max_num = array[i];
        }
    }

    return max_num;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n) {
    int max_num = find_max(values, n);

    int histogram[max_num + 1];
    memset(histogram, 0, sizeof (histogram));

    // Create a histogram of the sorted array
    for (int i = 0; i < n; ++i) {
        histogram[values[i]] += 1;
    }

    // Sort array
    for (int i = 0, array_iter = 0; i <= max_num; ++i) {
        if (histogram[i]) {
            // Insert j number of values from histogram
            for (int j = 0; j < histogram[i]; ++j, ++array_iter) {
                values[array_iter] = i;
            }
        }
    }
    return;
}

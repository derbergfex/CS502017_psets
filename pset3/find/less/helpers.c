/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <math.h>
#include "helpers.h"
#include "stdio.h"

/**
 * Returns true if value is in array of n values, else false.
 */

int binary(int arr[], int start, int finish, int target);

bool search(int value, int values[], int n)
{
    if (values[binary(values, 0, n - 1, value)] == value)
    {
        return true;
    }

    return false;
}

int binary(int arr[], int start, int finish, int target)
{
    if (finish >= start)
    {
        int mid = start + (finish - start) / 2;

        // If middle element is our target, we return its index.
        if (arr[mid] == target)
        {
            return mid;
        }

        // If our target is smaller than the middle element, it must be in the left half of the array.
        if (arr[mid] > target)
        {
            return binary(arr, start, mid - 1, target);
        }

        // Otherwise, the element must be present in the right half of the array.
        return binary(arr, mid + 1, finish, target);

    }

    // If element is not found.
    return -1;
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Since the last i elements are in place at this point.
        for (int j = 0; j < n - i - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
    return;
}


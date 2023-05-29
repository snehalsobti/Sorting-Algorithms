#include <iostream>
#include <string.h>
#include "func_dec.h"

// sorts the array arr in ascending (non-decreasing) order
// using Counting Sort Algorithm
// arr[] should have the elements in the range from 0 to k (k exclusive)
// Ideally for this algorithm to be fast enough, k should be linearly proportional to arrSize
// e.g -> if arrSize is 100, k should be small like 50 or 200 or 300 -> NOT 10000
void countingSort(int arr[], int arrSize, int k)
{
    int *count = new int[k];

    // Output array is being used for the purpose of handling non-primitive data types too
    int *output = new int[arrSize];

    memset(count, 0, static_cast <size_t> (k) * sizeof(int));

    // Fill count[] array such that count[i] represents the frequency of i in arr[]
    for (int index = 0; index < arrSize; index++)
    {
        count[arr[index]] += 1;
    }

    // Update count[] array such that count[i] represents the
    // frequency of elements greater than or equal to i in arr[]
    for (int index = 1; index < k; index++)
    {
        count[index] += count[index - 1];
    }

    // Fill in the output array
    // Iterate arr[] from arrSize - 1 to 0 --> to maintain stability of sorting algorithm
    for (int index = arrSize - 1; index >= 0; index--)
    {
        int indexOutput = count[arr[index]] - 1;
        output[indexOutput] = arr[index];
        count[arr[index]] -= 1;
    }

    // Copy the elements of output[] to arr[]
    copyElements(arr, output, arrSize);

    delete []output;
    delete []count;
}
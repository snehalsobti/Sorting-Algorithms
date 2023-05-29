#include <iostream>
#include <string.h>
#include "func_dec.h"

// sorts the array arr in ascending (non-decreasing) order
// using Radix Sort Algorithm
// arr[] should have the elements in the range from 0 to k (k exclusive)
// Unlike Counting Sort Algorithm, k can be quadratically or cubically proportional to arrSize
// e.g -> if arrSize is 100, k can be (arrSize)^2 i.e 10000 or (arrSize)^3 i.e 1000000
void radixSort(int arr[], int arrSize)
{
    // Finding the largest element in arr[]
    int largest = arr[0];
    for (int index = 1; index < arrSize; index++)
    {
        if (arr[index] > largest)
        {
            largest = arr[index];
        }
    }

    // Radix Sort involves sorting the elements by their digits
    // So, in a for loop, first we sort by ones (least significant digit) digit, then by tens digit, 
    // then by hundreds digit and so on......
    for (int exponent = 1; largest / exponent > 0; exponent *= 10)
    {
        countingSortSpecial(arr, arrSize, exponent);
    }
}

// helper function for radixSort
// this is basically counting sort but in this case the range of elements in arr is just 0-9
// Moreover, we have another parameter exponent
// which will decide the indices of arrays in the implementation
void countingSortSpecial(int arr[], int arrSize, int exponent)
{
    // Range of elements in arr[] is 0-9 (because they are digits of a number)
    int *count = new int[10];

    // Output array is being used for the purpose of handling non-primitive data types too
    int *output = new int[arrSize];

    memset(count, 0, static_cast <size_t> (10) * sizeof(int));

    // Fill count[] array such that count[i] represents the frequency of i in arr[]
    for (int index = 0; index < arrSize; index++)
    {
        count[(arr[index] / exponent) % 10] += 1;
    }

    // Update count[] array such that count[i] represents the
    // frequency of elements greater than or equal to i in arr[]
    for (int index = 1; index < 10; index++)
    {
        count[index] += count[index - 1];
    }

    // Fill in the output array
    // Iterate arr[] from arrSize - 1 to 0 --> to maintain stability of sorting algorithm
    for (int index = arrSize - 1; index >= 0; index--)
    {
        int indexOutput = count[(arr[index] / exponent) % 10] - 1;
        output[indexOutput] = arr[index];
        count[(arr[index] / exponent) % 10] -= 1;
    }

    // Copy the elements of output[] to arr[]
    copyElements(arr, output, arrSize);

    delete []output;
    delete []count;
}
#include <iostream>
#include "func_dec.h"

// sorts the array arr in ascending (non-decreasing) order
// using Insertion Sort Algorithm
void insertionSort(int arr[], int arrSize)
{
    for (int index = 1; index < arrSize; index++)
    {
        int toBeInserted = arr[index];
        int j = index;

        while (j > 0 && arr[j - 1] > toBeInserted)
        {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = toBeInserted;
    }
}
#include <iostream>
#include "func_dec.h"

// sorts the array arr in ascending (non-decreasing) order
// using Bubble Sort Algorithm
void bubbleSort(int arr[], int arrSize)
{
    // if througout the pass, there is no swap, this means the array is sorted
    bool swapped = true;

    for (int pass = 0; pass < arrSize - 1 && swapped; pass++)
    {
        swapped = false;

        for (int index = 1; index < arrSize - pass; index++)
        {
            if (arr[index] < arr[index - 1])
            {
                swap(arr[index], arr[index - 1]);
                swapped = true;
            }
        }
    }
}

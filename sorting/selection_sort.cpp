#include <iostream>
#include <algorithm>
#include "func_dec.h"

// sorts the array arr in ascending (non-decreasing) order
// using Selection Sort Algorithm
void selectionSort(int arr[], int arrSize)
{
    for (int pass = 0; pass < arrSize - 1; pass++)
    {
        int minElement = arr[pass];
        int minElementIndex = pass;

        for (int index = pass + 1; index < arrSize; index++)
        {
            if (arr[index] < minElement)
            {
                minElement = arr[index];
                minElementIndex = index;
            }
        }
        
        swap(arr[minElementIndex], arr[pass]);
    }
}
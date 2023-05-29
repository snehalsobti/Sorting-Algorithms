#include <iostream>
#include "func_dec.h"

// sorts the array arr in ascending (non-decreasing) order
// using Merge Sort Algorithm
void mergeSort(int arr[], int arrSize)
{
    mergeSortRecursive(arr, 0, arrSize - 1);
}

// recursive helper function for mergeSort
void mergeSortRecursive(int arr[], int low, int high)
{
    if (high > low)
    {
        int middle = (low + high) / 2;
        mergeSortRecursive(arr, low, middle);
        mergeSortRecursive(arr, middle + 1, high);
        merge(arr, low, middle, high);
    }
}

// helper function for mergeSort --> it merges the two sorted arrays
// the two sorted arrays are --> arr[low] to arr[middle] and arr[middle + 1] to arr[high]
void merge(int arr[], int low, int middle, int high)
{
    const int leftArrSize = middle - low + 1;
    const int rightArrSize = high - middle;

    int *leftArr = new int[leftArrSize];
    int *rightArr = new int[rightArrSize];

    // fill in leftArr and rightArr
    copyElements(leftArr, arr + low, leftArrSize);
    copyElements(rightArr, arr + low + leftArrSize, rightArrSize);

    int indexLeft = 0;
    int indexRight = 0;
    int indexMerged = low;

    // merge sorted arrays using two index approach
    // one index for left array and another one for right array
    for (; indexLeft < leftArrSize && indexRight < rightArrSize; indexMerged++)
    {
        if (leftArr[indexLeft] <= rightArr[indexRight])
        {
            arr[indexMerged] = leftArr[indexLeft];
            indexLeft++;
        }
        else
        {
            arr[indexMerged] = rightArr[indexRight];
            indexRight++;
        }
    }

    for (; indexLeft < leftArrSize; indexLeft++, indexMerged++)
    {
        arr[indexMerged] = leftArr[indexLeft];
    }

    for (; indexRight < rightArrSize; indexRight++, indexMerged++)
    {
        arr[indexMerged] = rightArr[indexRight];
    }

    delete []leftArr;
    delete []rightArr;
}
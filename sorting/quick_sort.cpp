#include <iostream>
#include "func_dec.h"

// sorts the array arr in ascending (non-decreasing) order
// using Quick Sort Algorithm
// using Lomuto Partition (0) or Hoare Partition (1) (whatever is passed in partitionAlgo)
void quickSort(int arr[], int arrSize, bool partitionAlgo)
{
    if (partitionAlgo == 0)
    {
        quickSortHelperLomuto(arr, 0, arrSize - 1, arrSize - 1);
    }
    else
    {
        quickSortHelperHoare(arr, 0, arrSize - 1, 0);
    }
}

// recursive helper function for quickSort if Lomuto partition is used
void quickSortHelperLomuto(int arr[], int low, int high, int pivotIndex)
{
    if (low < high)
    {
        int partitionIndex = lomutoPartition(arr, low, high, pivotIndex);
        quickSortHelperLomuto(arr, low, partitionIndex - 1, partitionIndex - 1);
        quickSortHelperLomuto(arr, partitionIndex + 1, high, high);
    }
}

// recursive helper function for quickSort if Hoare partition is used
void quickSortHelperHoare(int arr[], int low, int high, int pivotIndex)
{
    if (low < high)
    {
        int partitionIndex = hoarePartition(arr, low, high, pivotIndex);
        quickSortHelperHoare(arr, low, partitionIndex, low);
        quickSortHelperHoare(arr, partitionIndex + 1, high, partitionIndex + 1);
    }
}
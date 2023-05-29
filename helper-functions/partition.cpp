// This file contains helper functions for partition required for quick sort
// Two types of partition are used for quick sort in this project
// Lomuto Partition and Hoare Partition
#include <iostream>
#include "func_dec.h"

// Lomuto Partition
// Typically uses index high as pivot index but user can pass any pivotIndex
// Returns the correct index for the pivot in the sorted array 
// (the index where pivot should be in a sorted array)
int lomutoPartition(int arr[], int low, int high, int pivotIndex)
{
    // keep the pivot index as index high for typical Lomuto Partition
    swap(arr[high], arr[pivotIndex]);

    int j = static_cast <int> (low) - 1;
    int pivot = arr[high];

    for (int index = low; index < high; index++)
    {
        // swap the elements only when element less than pivot is found
        if (arr[index] < pivot)
        {
            j++;
            swap(arr[j], arr[index]);
        }
    }

    // place pivot in its correct position
    swap(arr[j + 1], arr[high]);

    return static_cast <int> (j + 1);
}

// Hoare Partition
// Typically uses index low as pivot index but user can pass any pivotIndex
// Unlike the Lomuto Partition, this does NOT place the pivot at its correct index
// Returns index j --> arr is partitioned such that elements from index low to j are less than 
// or equal to pivot and elements from j + 1 to high are greater than or equal to pivot
int hoarePartition(int arr[], int low, int high, int pivotIndex)
{
    // keep the pivot index as index low for typical Hoare Partition
    swap(arr[low], arr[pivotIndex]); 

    int pivot = arr[low];
    int left = static_cast <int> (low) - 1;
    int right = static_cast <int> (high) + 1;

    while (true)
    {
        // keep incrementing left until element greater than or equal to pivot is found
        do
        {
            left++;
        } while (arr[left] < pivot); 

        // keep decrementing right until element less than or equal to pivot is found
        do
        {
            right--;
        } while (arr[right] > pivot);

        // swap if left has not crossed right index yet
        // otherwise return index right (i.e the index j which partitions the array)
        if (left < right)
        {
            swap(arr[left], arr[right]);
        }
        else
        {
            return static_cast <int> (right);
        }
    }
}
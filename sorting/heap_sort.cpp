#include <iostream>
#include "func_dec.h"

// sorts the array arr in ascending (non-decreasing) order
// using Heap Sort Algorithm
// Use min heap if you want descending (non-increasing) order
void heapSort(int arr[], int arrSize)
{
    // Build a Max Heap
    buildHeap(arr, arrSize);

    // Repeatedly swap the root node (the largest) with last node of the heap
    // and decrease the size of heap by 1
    for (int heapSize = arrSize - 1; heapSize > 0; heapSize--)
    {
        swap(arr[0], arr[heapSize]);
        heapify(arr, heapSize, 0);
    }
}

// builds a max heap from elements of arr with size arrSize
void buildHeap(int arr[], int arrSize)
{
    int mid = arrSize / 2;
    for (int index = mid - 1; index >= 0; index--)
    {
        heapify(arr, arrSize, index);
    }
}

// heapifies (in a max heap way) the heap with size heapSize and root node being rootNode
void heapify(int arr[], int heapSize, int rootNode)
{
    int largest = rootNode;
    int left = 2 * rootNode + 1;
    int right = 2 * rootNode + 2;

    if (left < heapSize && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < heapSize && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != rootNode)
    {
        swap(arr[largest], arr[rootNode]);
        heapify(arr, heapSize, largest);
    }
}


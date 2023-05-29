// This file contains the declarations for all the sorting functions
// The sorting functions that have been implemented here -> sort in ascending order (non-decreasing)
// If you want to sort in the other order, there are two options:
// 1.) You can use these functions for sorting and then, reverse the array
// 2.) Modify the functions such that they sort in the other order

#ifndef SORTING_ALGO_H
#define SORTING_ALGO_H

#include <iostream>

// sorts the array arr in ascending (non-decreasing) order
// using Bubble Sort Algorithm
void bubbleSort(int arr[], int arrSize);

// sorts the array arr in ascending (non-decreasing) order
// using Insertion Sort Algorithm
void insertionSort(int arr[], int arrSize);

// sorts the array arr in ascending (non-decreasing) order
// using Selection Sort Algorithm
void selectionSort(int arr[], int arrSize);

// sorts the array arr in ascending (non-decreasing) order
// using Heap Sort Algorithm
void heapSort(int arr[], int arrSize);

// sorts the array arr in ascending (non-decreasing) order
// using Merge Sort Algorithm
void mergeSort(int arr[], int arrSize);

// sorts the array arr in ascending (non-decreasing) order
// using Quick Sort Algorithm
// using Lomuto Partition (0) or Hoare Partition (1) (whatever is passed in partitionAlgo)
void quickSort(int arr[], int arrSize, bool partitionAlgo);

// sorts the array arr in ascending (non-decreasing) order
// using Counting Sort Algorithm
// arr[] should have the elements in the range from 0 to k (k exclusive)
// Ideally for this algorithm to be fast enough, k should be linearly proportional to arrSize
// e.g -> if arrSize is 100, k should be small like 50 or 200 or 300 -> NOT 10000
void countingSort(int arr[], int arrSize, int k);

// sorts the array arr in ascending (non-decreasing) order
// using Radix Sort Algorithm
// arr[] should have the elements in the range from 0 to k (k exclusive)
// Unlike Counting Sort Algorithm, k can be quadratically or cubically proportional to arrSize
// e.g -> if arrSize is 100, k can be (arrSize)^2 i.e 10000 or (arrSize)^3 i.e 1000000
void radixSort(int arr[], int arrSize);

// sorts the array arr in ascending (non-decreasing) order
// using Bucket Sort Algorithm
// for this algorithm to be fast enough -> arr[] should have a fairly uniform distribution of elements
// k denotes the number of buckets (categories) being used
void bucketSort(int arr[], size_t arrSize, size_t k);

#endif
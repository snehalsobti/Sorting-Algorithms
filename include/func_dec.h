// This file contains the declarations for all the helper functions used throughout the project
#ifndef FUNC_DEF_H
#define FUNC_DEF_H

#include <chrono>
#include <iostream>
#include <vector>

// Generate a random integer in a range of start and end integers (both inclusive)
void generateRandomN(int start, int end, 
                            int arr[], int N);

// profile the function funcName --> calculate the time taken by the function execution
void profileFunc(std::chrono::time_point < std::chrono::high_resolution_clock > startTime,
                    std::string funcName);

// return true if the array is sorted (in ascending i.e non-decreasing order)
bool isArraySorted(int arr[], int arrSize);

// Print the array arr from index low to index high (both inclusive)
void printArray(int arr[], int arrSize, int low, int high);

// swap the elements in place
void swap(int &a, int &b);

// copies all the elements of arr to arrCopy
void copyElements(int arrCopy[], int arr[], int arrSize);

// helper function for mergeSort --> it is a recursive function
void mergeSortRecursive(int arr[], int low, int high);

// helper function for mergeSort --> it merges the two sorted arrays
// the two sorted arrays are --> arr[low] to arr[middle] and arr[middle + 1] to arr[high]
void merge(int arr[], int low, int middle, int high);

// Lomuto Partition
// Typically uses index high as pivot index but user can pass any pivotIndex
// Returns the correct index for the pivot in the sorted array 
// (the index where pivot should be in a sorted array)
int lomutoPartition(int arr[], int low, int high, int pivotIndex);

// Hoare Partition
// Typically uses index low as pivot index but user can pass any pivotIndex
// Unlike the Lomuto Partition, this does NOT place the pivot at its correct index
// Returns index j --> arr is partitioned such that elements from index low to j are less than 
// or equal to pivot and elements from j + 1 to high are greater than or equal to pivot
int hoarePartition(int arr[], int low, int high, int pivotIndex);

// recursive helper function for quickSort if Lomuto partition is used
void quickSortHelperLomuto(int arr[], int low, int high, int pivotIndex);

// recursive helper function for quickSort if Hoare partition is used
void quickSortHelperHoare(int arr[], int low, int high, int pivotIndex);

// builds a max heap from elements of arr with size arrSize
void buildHeap(int arr[], int arrSize);

// heapifies (in a max heap way) the heap with size heapSize and root node being rootNode
void heapify(int arr[], int heapSize, int rootNode);

// helper function for radixSort
// this is basically counting sort but in this case the range of elements in arr is just 0-9
// Moreover, we have another parameter exponent
// which will decide the indices of arrays in the implementation
void countingSortSpecial(int arr[], int arrSize, int exponent);

// helper function for bucketSort
// sorts the array arr in ascending (non-decreasing) order
// using Insertion Sort Algorithm
// takes vector as input instead of C-style array
void bucketSortHelper(std::vector < int > arr, size_t arrSize);

#endif

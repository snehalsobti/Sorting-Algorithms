#include <iostream> // For basic input output functions
#include <chrono> // For time calculation and manipulation functions such as finding time differece
#include "func_dec.h" // Contains declarations for helper functions 
#include "sorting_algo.h" // Contains declarations for sorting functions

int main(void)
{
    // size of the array to be sorted
    int ARR_SIZE = 100000;

    // start and end values (both inclusive) of the range for random number generation
    const int START_VALUE = 0;
    const int END_VALUE = INT32_MAX / 4 - 1;

    // declare array and allocate memory space for the array
    int *arr;
    arr = new int[ARR_SIZE];

    // Creating an array that will be passed to sorting functions to be sorted
    // Keep array arr always sorted and copy its elements to arrCopy before calling sorting function
    int *arrCopy;
    arrCopy = new int[ARR_SIZE];

    // Print a note to the terminal regarding time taken

    std::cout << "************************* NOTE *************************" << std::endl;
    std::cout << "If Array Size is as large as 100,000 - Slower sorting algorithms " <<
        "might take around 20-40 seconds.\nSo, Please wait for the output." << std::endl;
    std::cout << "********************************************************\n" << std::endl;

    std::cout << "Array Size for Slower Sorting Algorithms is "
                << ARR_SIZE / 1000000.0 << " million elements\n" << std::endl;

    // fill arr with random numbers
    generateRandomN(START_VALUE, END_VALUE, arr, ARR_SIZE);
    isArraySorted(arr, ARR_SIZE);

    // Sorting functions start here

    //////////////////////////////// SLOWER SORTING ALGORITHMS ////////////////////////////////    

    // BUBBLE SORT

    copyElements(arrCopy, arr, ARR_SIZE);

    auto startTime = std::chrono::high_resolution_clock::now();
    bubbleSort(arrCopy, ARR_SIZE);
    profileFunc(startTime, "Bubble Sort");

    isArraySorted(arrCopy, ARR_SIZE);

    // SELECTION SORT

    copyElements(arrCopy, arr, ARR_SIZE);

    startTime = std::chrono::high_resolution_clock::now();
    selectionSort(arrCopy, ARR_SIZE);
    profileFunc(startTime, "Selection Sort");

    isArraySorted(arrCopy, ARR_SIZE);

    // INSERTION SORT

    copyElements(arrCopy, arr, ARR_SIZE);

    startTime = std::chrono::high_resolution_clock::now();
    insertionSort(arrCopy, ARR_SIZE);
    profileFunc(startTime, "Insertion Sort");

    isArraySorted(arrCopy, ARR_SIZE);

    // deallocate the space allocated to arr --> to prevent memory leaks
    delete []arr;
    arr = NULL;
    delete []arrCopy;
    arrCopy = NULL;

    // Changing arr, arrCopy, ARR_SIZE for faster sorting algorithms         

    // size of the array to be sorted
    ARR_SIZE = 10000000;

    // reallocate memory space for the array arr
    arr = new int[ARR_SIZE];

    // Creating an array that will be passed to sorting functions to be sorted
    // Keep array arr always sorted and copy its elements to arrCopy before calling sorting function
    arrCopy = new int[ARR_SIZE];   

    std::cout << "\n********************************************************\n" << std::endl;
    std::cout << "Changing array size now.....\n" <<
                "Array Size for Faster Sorting Algorithms is " << ARR_SIZE / 1000000.0 <<
                 " million elements\n" <<
                std::endl;       

    // fill arr with random numbers
    generateRandomN(START_VALUE, END_VALUE, arr, ARR_SIZE);
    isArraySorted(arr, ARR_SIZE);   

    //////////////////////////////// FASTER SORTING ALGORITHMS ////////////////////////////////

    // HEAP SORT

    copyElements(arrCopy, arr, ARR_SIZE);

    startTime = std::chrono::high_resolution_clock::now();
    heapSort(arrCopy, ARR_SIZE);
    profileFunc(startTime, "Heap Sort");

    isArraySorted(arrCopy, ARR_SIZE);

    // MERGE SORT

    copyElements(arrCopy, arr, ARR_SIZE);

    startTime = std::chrono::high_resolution_clock::now();
    mergeSort(arrCopy, ARR_SIZE);
    profileFunc(startTime, "Merge Sort");

    isArraySorted(arrCopy, ARR_SIZE);

    // QUICK SORT using Lomuto Partition

    copyElements(arrCopy, arr, ARR_SIZE);

    startTime = std::chrono::high_resolution_clock::now();
    quickSort(arrCopy, ARR_SIZE, 0);
    profileFunc(startTime, "Quick Sort (Lomuto)");

    isArraySorted(arrCopy, ARR_SIZE);

    // QUICK SORT using Hoare Partition

    copyElements(arrCopy, arr, ARR_SIZE);

    startTime = std::chrono::high_resolution_clock::now();
    quickSort(arrCopy, ARR_SIZE, 1);
    profileFunc(startTime, "Quick Sort (Hoare)");

    isArraySorted(arrCopy, ARR_SIZE);

    std::cout << "\n********************************************************\n" << std::endl;
    std::cout << "Special Case Algorithms starting now.....\n" <<
                "NOTE: the number of elements (n) is " << ARR_SIZE / 1000000.0 <<
                " million elements\n" << "And the range of elements is 0 to k which is approx. " <<
                ARR_SIZE / (2 * 1000000.0) << " million\n" <<
                "So, k is small as compared to n (k ~ n / 2)\n" <<
                std::endl;       

    // COUNTING SORT

    copyElements(arrCopy, arr, ARR_SIZE);

    startTime = std::chrono::high_resolution_clock::now();
    countingSort(arrCopy, ARR_SIZE, END_VALUE + 1);
    profileFunc(startTime, "Counting Sort");

    isArraySorted(arrCopy, ARR_SIZE);

    // RADIX SORT

    copyElements(arrCopy, arr, ARR_SIZE);

    startTime = std::chrono::high_resolution_clock::now();
    radixSort(arrCopy, ARR_SIZE);
    profileFunc(startTime, "Radix Sort");

    isArraySorted(arrCopy, ARR_SIZE);

    // BUCKET SORT

    copyElements(arrCopy, arr, ARR_SIZE);

    startTime = std::chrono::high_resolution_clock::now();
    bucketSort(arrCopy, static_cast < size_t > (ARR_SIZE), static_cast < size_t > (ARR_SIZE));
    profileFunc(startTime, "Bucket Sort");

    isArraySorted(arrCopy, ARR_SIZE);

    // deallocate the space allocated to arr --> to prevent memory leaks
    delete []arr;
    arr = NULL;
    delete []arrCopy;
    arrCopy = NULL;
}
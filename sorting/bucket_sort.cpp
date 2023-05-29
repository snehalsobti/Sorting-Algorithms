#include <iostream>
#include <vector>
#include "func_dec.h"
#include "sorting_algo.h"

// sorts the array arr in ascending (non-decreasing) order
// using Bucket Sort Algorithm
// for this algorithm to be fast enough -> arr[] should have a fairly uniform distribution of elements
// k denotes the number of buckets (categories) being used
void bucketSort(int arr[], size_t arrSize, size_t k)
{
    // Find the largest element in arr[]
    int largest = arr[0];
    for (size_t index = 1; index < arrSize; index++)
    {
        if (arr[index] > largest)
        {
            largest = arr[index];
        }
    }

    // Create the buckets and fill them with appropriate elements
    std::vector < std::vector < int > > buckets;
    buckets.resize(k);

    // largest exists in the array and must be in the last bucket
    // our formula for index is (k * arr[index]) / largest
    // So, in that case, the index for largest itself will come out to be k
    // which will be out of bounds of vector buckets (it should be k - 1)
    // Hence, we increment largest by 1
    largest += 1;

    size_t bucketIndex = 0;

    for (size_t index = 0; index < arrSize; index++)
    {
        bucketIndex = (k * static_cast < size_t > (arr[index])) / static_cast < size_t > (largest);
        buckets[bucketIndex].push_back(arr[index]);
    }

    // Sort each bucket individually
    // If arr has fairly uniform distribution and k is also proportional to arrSize (like arrSize / 2)
    // then, there will be around 1-3 (constant number) elements in each bucket
    // So, use Insertion Sort algorithm which is the best for small arrays
    for (bucketIndex = 0; bucketIndex < k; bucketIndex++)
    {
        bucketSortHelper(buckets[bucketIndex], buckets[bucketIndex].size());
    }

    size_t arrIndex = 0;

    // Combine all the buckets back together to form a sorted array arr[]
    for (bucketIndex = 0; bucketIndex < k; bucketIndex++)
    {
        for (size_t index = 0; index < buckets[bucketIndex].size(); index++)
        {
            arr[arrIndex] = buckets[bucketIndex][index];
            arrIndex++;
        }
    }
}

// helper function for bucketSort
// sorts the array arr in ascending (non-decreasing) order
// using Insertion Sort Algorithm
// takes vector as input instead of C-style array
void bucketSortHelper(std::vector < int > arr, size_t arrSize)
{
    for (size_t index = 1; index < arrSize; index++)
    {
        int toBeInserted = arr[index];
        size_t j = index;

        while (j > 0 && arr[j - 1] > toBeInserted)
        {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = toBeInserted;
    }
}
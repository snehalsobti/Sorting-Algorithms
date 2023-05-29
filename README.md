# Sorting-Algorithms
Implementation of nine (9) sorting algorithms (in C++), along with their performance comparison using chrono library

## Performance Comparison
The sorting algorithms have been categorised into Slower and Faster Sorting Algorithms. For Slower Sorting Algorithms, by default, the array size being used is 0.1 Million elements and for Faster Sorting Algorithms, by default, the array size being used is 10 Million elements --> These values can be modified through the ARR_SIZE variable in main.cpp   
There are Special Case Sorting Algorithms as well which are included in the category of Faster Sorting Algorithms. These are Counting Sort, Radix Sort and Bucket Sort.   
### Counting Sort
Counting Sort is suitable for cases when the elements of the array are in a small range ("small" is relative to the array size).  
Assume the array size to be n, the maximum part in the range of elements (k) should be proportional to n i.e n / 2, or 2n or 3n BUT definitely NOT n<sup>2</sup> or n<sup>3</sup>   
By default, in the code, the range has been set to 0 to appox. 0.05 Million so that speed of Counting Sort is comparable to other faster algorithms
### Radix Sort
Radix Sort is fast even for the cases when the maximum part in the range of elements (k) is large such as proportional to n<sup>2</sup> or n<sup>3</sup> where n is the array size  
By default, in the code, the range has been set to 0 to appox. 0.05 Million so that speed of Radix Sort is comparable to other faster algorithms. The maximum part in the range of elements (k) can be modified through the END_VALUE variable in main.cpp  
*NOTE: Do not set END_VALUE to INT32_MAX or a greater value than that*  
### Bucket Sort
Bucket Sort is suitable for cases when the elements of the array are fairly in a uniform distribution. As I have used uniform_int_distribution while generating random numbers that fill in the array to be sorted, the array is fairly in a uniform distribution.  

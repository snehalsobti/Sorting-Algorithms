#include <iostream>

// return true if the array is sorted (in ascending i.e non-decreasing order)
bool isArraySorted(int arr[], int arrSize)
{
    if (arrSize <= 1)
    {
        std::cout << "Array: Sorted\n" << std::endl;
        return true;
    }

    for (int index = 1; index < arrSize; index++)
    {
        if (arr[index] < arr[index - 1])
        {
            std::cout << "Array: Not Sorted\n" << std::endl;
            return false;
        }
    }

    std::cout << "Array: Sorted\n" << std::endl;
    return true;
}
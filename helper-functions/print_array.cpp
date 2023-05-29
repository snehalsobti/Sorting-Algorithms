#include <iostream>

// Print the array arr from index low to index high (both inclusive)
void printArray(int arr[], int arrSize, int low, int high)
{
    if (high < low)
    {
        std::cout << "Incorrect Parameters: index high must be greater than or equal to low" << std::endl;
    }

    std::cout << "Printing the array......" << std::endl;

    for (int index = low; index < arrSize && index <= high; index++)
    {
        std::cout << arr[index] << ' ';
    }

    std::cout << std::endl;
}


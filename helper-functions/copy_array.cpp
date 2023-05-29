#include <iostream>

// copies all the elements of arr to arrCopy
void copyElements(int arrCopy[], int arr[], int arrSize)
{
    size_t numElem = static_cast <unsigned int> (arrSize);
    memcpy(arrCopy, arr, numElem * sizeof(int));
}
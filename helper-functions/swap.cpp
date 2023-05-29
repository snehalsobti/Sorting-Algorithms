#include <iostream>

// swap the elements in place
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
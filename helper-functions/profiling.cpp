#include <iostream>
#include <string>
#include <chrono>

// profile the function funcName --> calculate the time taken by the function execution
void profileFunc(std::chrono::time_point < std::chrono::high_resolution_clock > startTime,
                    std::string funcName)
{
    // calculate end time
    auto const endTime = std::chrono::high_resolution_clock::now(); 

    // calculate the time difference
    // cast the time difference of startTime and endTime to milliseconds
    auto const elapsedTime = 
        std::chrono::duration_cast < std::chrono::duration < double > > (endTime - startTime);
 
    // print the time taken by the function funcName
    std::cout << "Time taken by function " << funcName << ": " 
         << elapsedTime.count() << " seconds" << std::endl;
}
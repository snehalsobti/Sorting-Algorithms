#include <random>
#include <time.h>

// Generate a series of N random integers in a range of start and end integers (both inclusive)
void generateRandomN(int start, int end, 
                            int arr[], int N)
{
    unsigned int startNum = static_cast <unsigned int> (start);
    unsigned int endNum = static_cast <unsigned int> (end);

    // create a uniform distribution of integers between start and end
    typedef std::mt19937 range_type;
    std::uniform_int_distribution < range_type::result_type > uniformDist(startNum, endNum);

    range_type range;

    // seed range using time(NULL) i.e  
    // the number of seconds elapsed since 00:00:00 hours, GMT (Greenwich Mean Time), January 1, 1970
    range_type::result_type const seedValue = static_cast < unsigned int > (time(NULL));
    range.seed(seedValue);

    // Fill arr with random numbers
    for (int index = 0; index < N; index++)
    {
        // generate random integer
        range_type::result_type random_number = uniformDist(range);

        arr[index] = static_cast <int> (random_number);
    }
}
#include "ranges.h"

int main()
{
    std::cout << "Input a size of range: ";
    int range;
    std::cin >> range;
    std::cout << "Input integer numbers(q for quit): ";
    std::vector<int> numbers;
    int number;
    while(std::cin >> number)
        numbers.push_back(number);

    std::cin.clear();
    std::cin.get();

    Ranges ranges(range, numbers);
    ranges.show();

    std::cout << "\n\nInput a size of array: ";
    int size;
    std::cin >> size;
    int *arr(new int [size]);
    std::cout << "Input " << size <<" integer numbers: ";
    for(int count(0); count < size; ++count)
        std::cin >> arr[count];

    ranges.set(range, arr, size);
    ranges.show();

    delete [] arr;

    std::cout << "\nDone!\n\n";

    return 0;
}

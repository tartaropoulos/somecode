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

    Ranges ranges(range, numbers);
    ranges.show();

    std::cout << "\nDone!\n\n";

    return 0;
}

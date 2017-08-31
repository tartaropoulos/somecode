#include "ranges.h"

Ranges::Ranges(int range, std::vector<int> numbers)
{
    m_range = range;
    m_numbers = numbers;

    fill();
}

Ranges::Ranges(int range, int *arr, int size)
{
    for(int count(0); count < size; ++count)
        m_numbers.push_back(arr[count]);

    m_range = range;

    fill();
}

void Ranges::show()
{
    for(auto number : m_uniqueNumbers)
    {
        std::pair<std::multimap<int, int>::iterator
                , std::multimap<int, int>::iterator>
                  itMaps = m_changedNumbers.equal_range(number);
        std::cout << "Numbers in range from " << number * m_range
                  << " to " << number * m_range + m_range << ": ";
        for(std::multimap<int, int>::iterator itMap = itMaps.first;
            itMap != itMaps.second; ++itMap)
            std::cout << " " << itMap->second;
        std::cout << std::endl;
    }
}

void Ranges::set(int range, std::vector<int> numbers)
{
    m_changedNumbers.clear();
    m_uniqueNumbers.clear();

    m_range = range;
    m_numbers = numbers;

    fill();
}

void Ranges::set(int range, int *arr, int size)
{
    m_numbers.clear();
    m_changedNumbers.clear();
    m_uniqueNumbers.clear();

    for(int count(0); count < size; ++count)
        m_numbers.push_back(arr[count]);

    m_range = range;

    fill();
}

void Ranges::fill()
{
    std::transform(m_numbers.begin()
                 , m_numbers.end()
                 , std::inserter(m_changedNumbers, m_changedNumbers.begin())
                 , [=](int x){return std::pair<int, int>(x / m_range, x);});

    std::transform(m_changedNumbers.begin()
                 , m_changedNumbers.end()
                 , std::inserter(m_uniqueNumbers, m_uniqueNumbers.begin())
                 , [](std::pair<int, int> x){return x.first;});
}

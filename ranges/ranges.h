#ifndef RANGES_H
#define RANGES_H

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

class Ranges
{
public:
    Ranges() : m_range(0) {}
    Ranges(int range, std::vector<int> numbers);
    Ranges(int range, int *arr, int size);

    void show();
    void set(int range, std::vector<int> numbers);
    void set(int range, int *arr, int size);
private:
    int m_range;
    std::vector<int> m_numbers;
    std::multimap<int, int> m_changedNumbers;
    std::set<int> m_uniqueNumbers;

    void fill();
};

#endif //RANGES_H

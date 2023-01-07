#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end)
{
    while (begin != end)
    {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

int main(void)
{
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    auto result = std::find(vec.begin(), vec.end(), 3);

    auto current = vec.begin();
    while (true)
    {
        if ((current = std::find_if(current, vec.end(), [](int i)
                                    { return i % 3 == 2; })) == vec.end())
            break;
        std::cout << "3 으로 나눈 나머지가 2인 원소는 : " << *(current++) << " 이다" << std::endl;
    }

    return 0;
}
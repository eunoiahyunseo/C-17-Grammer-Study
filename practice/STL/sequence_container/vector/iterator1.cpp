#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T> vec)
{
    // 전체 벡터를 출력하기
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
        std::cout << *itr << std::endl;
}

template <typename T>
void print_vector_range_based(std::vector<T> &vec)
{
    for (const auto& elem : vec)
        std::cout << elem << std::endl;
}

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << "처음 벡터 상태" << std::endl;
    print_vector(vec);
    std::cout << "----------------------------" << std::endl;

    std::vector<int>::iterator itr = vec.begin() + 2;

    *itr = 50;

    print_vector(vec);

    std::cout << "----------------------------" << std::endl;
    // std::vector<int>::const_iterator citr = vec.cbegin() + 2;
    std::vector<int>::reverse_iterator r_iter = vec.rbegin();
    for (; r_iter != vec.rend(); r_iter++)
    {
        std::cout << *r_iter << std::endl;
    }

    std::cout << "----------- print vector_range_based -----------" << std::endl;
    print_vector_range_based(vec);
}

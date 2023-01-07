#include <iostream>
#include <array>

void print_array(const std::array<int, 5> &ary)
{
    for (int i = 0; i < ary.size(); i++)
    {
        std::cout << ary[i] << " ";
    }
    std::cout << std::endl;
}
int main(void)
{
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    print_array(arr);

    return 0;
}
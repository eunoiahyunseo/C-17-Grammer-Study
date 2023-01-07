#include <iostream>
#include <string>

template <typename T>
struct Compare
{
    bool operator()(const T &a, const T &b) { return a < b; }
};

template <typename T, typename Comp = Compare<T>>
T Min(T a, T b)
{
    Comp comp;
    if (comp(a, b))
    {
        return a;
    }
    return b;
}

int main()
{
    int a = 3, b = 5;
    std::cout << "Min: " << a << " , " << b << " :: " << Min(a, b) << std::endl;
}
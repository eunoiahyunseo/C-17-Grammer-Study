#include <iostream>
#include <string>

template <typename T>
class Vector
{
    T *data;
    int capacity;
    int length;

public:
    // constructor
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(T s)
    {
        if (capacity <= length)
        {
            T *temp = new T[capacity * 2];
            for (int i = 0; i < length; i++)
                temp[i] = data[i];

            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length++] = s;
    }

    // 임의의 위치에 원소에 접근한다
    T operator[](int i) { return data[i]; }

    // x번째 위치한 원소를 제거한다.
    void remove(int x)
    {
        for (int i = x + 1; i < length; i++)
            data[i - 1] = data[i];
        length--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() { return length; }

    // i번쨰 원소와 j번쨰 원소 위치를 바꾼다.
    void swap(int i, int j)
    {
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    // 소멸자
    ~Vector()
    {
        if (data)
            delete[] data;
    }
};

template <typename Cont, typename Comp>
void bubble_sort(Cont &cont, Comp &comp)
{
    for (int i = 0; i < cont.size(); i++)
        for (int j = i + 1; j < cont.size(); j++)
            if (!comp(cont[i], cont[j]))
                cont.swap(i, j);
}

// bubble_sort에서 함수는 아니지만, 함수인척을 하는 객체를 함수 객체(Functor)라고 부릅니다.
struct Comp1
{
    bool operator()(int a, int b) { return a > b; }
};

struct Comp2
{
    bool operator()(int a, int b) { return a < b; }
};

int main(void)
{
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(1);
    int_vec.push_back(2);
    int_vec.push_back(8);
    int_vec.push_back(5);
    int_vec.push_back(3);

    Comp1 comp1;
    bubble_sort(int_vec, comp1);

    std::cout << std::endl
              << std::endl
              << "내림차순 정렬 이후 ---- " << std::endl;

    for (int i = 0; i < int_vec.size(); i++)
    {
        std::cout << int_vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
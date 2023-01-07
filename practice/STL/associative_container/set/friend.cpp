#include <iostream>

class A
{
private:
    void private_func() {}
    int private_num;

    // B는 A의 친구!
    friend class B;

    // func은 A의 친구!
    friend void func();
};

class B
{
public:
    void b()
    {
        A a;

        // 비록 private 함수이 필드들이지만 친구이기 때문에 접근이 가능합니다.
        a.private_func();
        a.private_num = 2;
    }
};

void func()
{
    A a;

    // 비록 private 함수의 필드들이지만 위와 마찬가지로 친구이기 때문에 접근 가능합니다.
    a.private_func();
    a.private_num = 2;
}

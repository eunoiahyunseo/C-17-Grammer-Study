#include <iostream>
#include <string>

int main()
{
    std::string s = "abc";
    std::string t = "def";
    std::string s2 = s;

    std::cout << s << "와 같이 : " << s.length() << std::endl;
    std::cout << s << " 뒤에 " << t << " 를 붙이면 : " << s << t << std::endl;
}
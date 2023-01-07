#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(const std::multimap<K, V> &m)
{
    for (const auto &kv : m)
        std::cout << kv.first << " " << kv.second << std::endl;
}

int main()
{
    std::multimap<int, std::string> m;
    m.insert(std::make_pair(1, "hello"));
    m.insert(std::make_pair(1, "hi"));
    m.insert(std::make_pair(1, "ahihi"));
    m.insert(std::make_pair(2, "bye"));
    m.insert(std::make_pair(2, "baba"));

    print_map(m);

    std::cout << "--------------------" << std::endl;

    // 1을 키로 가지는 반복자들의 시작과 끝을
    // std::pair로 만들어서 리턴한다.
    auto range = m.equal_range(1);
    for (auto itr = range.first; itr != range.second; ++itr)
        std::cout << itr->first << " : " << itr->second << " " << std::endl;
}
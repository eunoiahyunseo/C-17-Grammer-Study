#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V> &m)
{
    for (auto itr = m.begin(); itr != m.end(); ++itr)
        std::cout << itr->first << " " << itr->second << std::endl;
}

template <typename K, typename V>
void search_and_print(std::map<K, V> &m, K key)
{
    auto itr = m.find(key);
    if (itr != m.end())
        std::cout << key << " --> " << itr->second << std::endl;
    else
        std::cout << key << "은(는) 목록에 없습니다" << std::endl;
}

int main()
{
    std::map<std::string, double> pitcher_list;

    pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
    pitcher_list.insert(std::pair<std::string, double>("해커", 2.93));

    pitcher_list.insert(std::pair<std::string, double>("피어밴드", 2.95));

    pitcher_list.insert(std::make_pair("차우친", 3.04));
    pitcher_list.insert(std::make_pair("장원준", 3.05));
    pitcher_list.insert(std::make_pair("핵터", 3.09));

    pitcher_list["니퍼트"] = 3.56;
    pitcher_list["박종훈"] = 3.76;
    pitcher_list["켈리"] = 3.90;

    print_map(pitcher_list);

    std::cout << "박세웅 방어율은? :: " << pitcher_list["박세웅"] << std::endl;
}
#include <iostream>
#include <map>

int main()
{
    std::map<char, char> m;
    // m.insert(std::pair<char, char>('a', 'A'));
    // m.insert(std::pair<char, char>('b', 'B'));
    m['1'] = '1';
    m['2'] = '2';

    // const表示只读
    for (const auto &elem : m)
    {
        std::cout << elem.first << " " << elem.second << std::endl;
    }

    std::multimap<std::string, int> mm;
    // error
    // mm["a"] = 1;
    // mm["a"] = 2;
    // mm["a"] = 3;
    // mm["b"] = 4;

    mm.insert(std::pair<std::string, int>("a", 1));
    mm.insert(std::pair<std::string, int>("a", 2));
    mm.insert(std::pair<std::string, int>("a", 3));
    mm.insert(std::pair<std::string, int>("b", 4));

    for (const auto &elem : mm)
    {
        std::cout << elem.first << " " << elem.second << std::endl;
    }
    return 0;
}
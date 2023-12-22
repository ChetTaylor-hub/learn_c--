/*函数模板*/

#include <iostream>
#include <string.h>

class Person
{
private:
    std::string m_name;
    int m_age;

public:
    Person(std::string name, int age) : m_name(name), m_age(age) {}
    int getAge() { return m_age; }
    std::string getName() { return m_name; }
};

template <class T>
T compare(T a, T b)
{
    return a > b ? a : b;
}

template <>
char *compare(char *a, char *b)
{
    return strcmp(a, b) > 0 ? a : b;
}

template <>
Person &compare(Person &a, Person &b)
{
    return a.getAge() > b.getAge() ? a : b;
}

int main()
{
    Person p1("zhangsan", 18);
    Person p2("lisi", 20);

    std::cout << compare(1, 2) << std::endl;
    std::cout << compare(1.1, 2.2) << std::endl;
    std::cout << compare("abc", "adc") << std::endl;
    std::cout << compare(p1, p2).getName() << std::endl;

    return 0;
}
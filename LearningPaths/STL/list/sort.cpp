/*list 排序案例*/

#include <iostream>
#include <list>

class Person
{
public:
    std::string m_Name;
    int m_Age;
    int m_Height;

public:
    Person(std::string name, int age, int height) : m_Name(name), m_Age(age), m_Height(height) {}
    ~Person() {}
};

bool personCompare(Person a, Person b)
{
    if (a.m_Age == b.m_Age)
        return a.m_Height < b.m_Height;
    return a.m_Age < b.m_Age;
}

void printList(const std::list<Person> &l)
{
    auto a = Person("ct", 1, 1);

    for (auto it = l.begin(); it != l.end(); it++)
    {
        std::cout << "name: " << (*it).m_Name << " age: " << (*it).m_Age << " height: " << (*it).m_Height << std::endl;
    }
}

int main()
{

    std::list<Person> l;
    for (int i = 10; i > 0; i--)
    {
        Person p("ct", i * 10, 100 - i);
        l.push_back(p);
    }
    // std::list<Person>::iterator it = l.begin();
    // (*(++it)).m_Age = 10;
    printList(l);
    l.sort(personCompare);
    std::cout << "-----------------------" << std::endl;
    printList(l);

    return 0;
}
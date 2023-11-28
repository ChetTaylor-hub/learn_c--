/*vector自定义数据类型的遍历方式*/

#include <iostream>
#include <vector>
#include <algorithm>

class Person
{
public:
    Person(std::string name, int age) : m_Name(name), m_Age(age) {}
    std::string m_Name;
    int m_Age;
};

void show(Person val)
{
    std::cout << "The second way: " << val.m_Name << std::endl;
}

int main()
{
    std::vector<Person> array;

    for (int i = 0; i < 10; i++)
    {
        Person person("TaoChen", 21);
        array.push_back(person);
    }

    // 第一种遍历方式
    for (std::vector<Person>::iterator i = array.begin(); i != array.end(); i++)
    {
        // iterator对象可以看成指针，begin()返回指向第一个元素的指针，end()返回最后一个元素的下一个元素的（此元素无意义）指针
        // i是指针，*i就可以取出对应元素
        std::cout << "The first way: " << i->m_Name << std::endl;
    }

    // 第二种便利方式
    // 转到for_each的定义，可以看到向show函数传入的参数是*i(i代表指针)
    std::for_each(array.begin(), array.end(), show);

    return 0;
}
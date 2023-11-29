/*提前开辟预留空间，防止多次重复开辟空间*/

#include <iostream>
#include <vector>

// 不使用reserve
void test01()
{
    std::vector<int> v;

    long num = 0;
    int *p = nullptr;

    for (int i = 0; i < 1000000000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    std::cout << num << std::endl;
    // 31次
}

// 使用reserve
void test02()
{
    std::vector<int> v;
    v.reserve(1000000000);

    long num = 0;
    int *p = nullptr;

    for (int i = 0; i < 1000000000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    std::cout << num << std::endl;
    // 1次
}

int main()
{

    test01();
    test02();

    return 0;
}
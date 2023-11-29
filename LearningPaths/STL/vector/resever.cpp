/*提前开辟预留空间，防止多次重复开辟空间
当数组vector达到最大容量时，编译器会重新开辟一块更大的空间，并将指针重新指向新开辟的空间
记录指针的改变次数可以查看开辟空间次数
*/

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
        if (p != &v[0]) // 判断指针是否发生变换
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
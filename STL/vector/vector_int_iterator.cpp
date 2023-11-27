/*vector内置数据类型的遍历方式*/

#include <iostream>
#include <vector>
#include <algorithm>

void show(int val)
{
    std::cout << "The second way: " << val << std::endl;
}

int main()
{
    std::vector<int> array = {1, 2, 3, 4, 5, 6};

    // 第一种遍历方式
    for (std::vector<int>::iterator i = array.begin(); i != array.end(); i++)
    {
        // iterator对象可以看成指针，begin()返回指向第一个元素的指针，end()返回最后一个元素的下一个元素的（此元素无意义）指针
        // i是指针，*i就可以取出对应元素
        std::cout << "The first way: " << *i << std::endl;
    }

    // 第二种便利方式
    // 转到for_each的定义，可以看到向show函数传入的参数是*i(i代表指针)
    std::for_each(array.begin(), array.end(), show);

    return 0;
}
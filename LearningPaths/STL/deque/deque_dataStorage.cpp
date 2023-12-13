/*deque的数据存取操作*/

#include <iostream>
#include <deque>

int main()
{
    std::deque<int> d;
    for (int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }

    // 索引访问，与vector相同
    std::cout << d[1] << std::endl;

    // 访问最后一个元素，vector没有
    std::cout << d.back() << std::endl;

    // 访问第一个元素，vector没有
    std::cout << d.front() << std::endl;

    return 0;
}

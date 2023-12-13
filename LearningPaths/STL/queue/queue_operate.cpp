/*队里的基本操作*/

#include <iostream>
#include <queue>

int main()
{
    std::queue<int> q;

    // 入队操作
    q.push(1);
    q.push(2);
    q.push(3);

    // 出队
    q.pop();

    // 返回队头，队尾
    std::cout << q.front() << std::endl;
    std::cout << q.back() << std::endl;

    // 大小操作
    std::cout << q.empty() << std::endl;
    std::cout << q.size() << std::endl;

    std::queue<int> q2(q); // 拷贝构造
    return 0;
}
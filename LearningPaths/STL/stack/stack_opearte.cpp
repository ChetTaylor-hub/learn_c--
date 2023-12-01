/*栈的基本操作*/

#include <iostream>
#include <stack>

int main()
{
    std::stack<int> s; // 栈初始化

    // 入栈操作
    s.push(1);
    s.push(2);
    s.push(3);

    s.pop(); // 出栈，无返回值

    std::cout << s.top() << std::endl; // 返回栈顶元素

    std::stack<int> s2(s); // 拷贝构造

    return 0;
}
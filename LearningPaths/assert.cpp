/*assert的使用，常用于判断起始状态和终末状态*/

#include <iostream>
#include <cassert>

int main()
{
    int a = 1;
    int b = 2;
    assert(a == b);
    std::cout << "a == b" << std::endl;

    return 0;
}
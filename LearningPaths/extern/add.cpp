/*调用add.c的相加函数*/

#include <iostream>
extern "C"
{
#include "add.h"
}

int main()
{
    int a = 1;
    int b = 2;
    int c = add(a, b);

    std::cout << "c = " << c << std::endl;

    return 0;
}

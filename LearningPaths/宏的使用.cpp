/*宏的使用*/

#include <iostream>

#define Max(a, b) ((a) > (b) ? (a) : (b))
#define DEBUG

int main()
{
    std::cout << Max(1, 2) << std::endl;

#ifdef DEBUG
    std::cout << "Debug" << std::endl;
#else
    std::cout << "Release" << std::endl;
#endif

    return 0;
}
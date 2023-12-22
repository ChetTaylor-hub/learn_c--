#include <iostream>
#include <iomanip>

int main()
{
    std::cout << std::setw(10) << std::setfill('*') << 77 << std::endl;
    std::cout << std::setw(10) << std::setfill('*') << 777 << std::endl;
    std::cout << std::setw(10) << std::setfill('*') << 7777 << std::endl;
    std::cout << std::setw(10) << std::setfill(' ') << 77777 << std::endl;
    std::cout << std::setw(10) << std::setfill(' ') << 777777 << std::endl;

    // std::setw(10) << std::setfill('-') << std::left << "sss" 可以看成一组：setw设置宽度，setfill设置填充字符，left设置左对齐，"sss"为输出的字符串,注意严格遵守顺序
    std::cout << std::setw(20) << std::setfill('-') << std::left << "sss" << std::setw(10) << std::right << std::setfill('-') << 77 << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << std::left << "ssssssssss" << std::setw(10) << std::right << std::setfill('-') << 7777 << std::endl;

    return 0;
}
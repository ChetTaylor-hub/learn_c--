/*union的使用*/

#include <iostream>

int main()
{
    union
    {
        int a;
        double b;
    } c;
    c.a = 66;
    std::cout << "c.a = " << c.a << std::endl;
    std::cout << "c.b = " << c.b << std::endl;
    c.b = 'B';
    std::cout << "c.a = " << c.a << std::endl;
    std::cout << "c.b = " << c.b << std::endl;

    return 0;
}
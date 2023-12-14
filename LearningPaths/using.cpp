/*using的使用*/

#include <iostream>

class Base
{
public:
    void f(int i) { std::cout << "Base::f(int)" << std::endl; }
    void f(double d) { std::cout << "Base::f(double)" << std::endl; }
};

class Derived : public Base
{
public:
    using Base::f; // 如果注释，Base的f函数将被隐藏
    void f(std::string s) { std::cout << "Derived::f(string)" << std::endl; }
};

int main()
{
    // 函数重载时的using

    Derived d;
    d.f(1);       // 调用Base::f(int)
    d.f(1.0);     // 调用Base::f(double)
    d.f("hello"); // 调用Derived::f(string)

    return 0;
}
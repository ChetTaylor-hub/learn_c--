#include <iostream>

class Base
{
private:
    int m_a;

public:
    Base(int a) : m_a(a) { std::cout << "Base::Base()" << std::endl; }
    virtual void func1() = 0;
    virtual ~Base() { std::cout << "Base::~Base()" << std::endl; }
};

class Derived : public Base
{
private:
    int m_b;

public:
    Derived(int a, int b) : Base(a), m_b(b) { std::cout << "Derived::Derived()" << std::endl; }
    virtual void func1()
    {
        std::cout << "Derived::func1()" << std::endl;
    }

    ~Derived() { std::cout << "Derived::~Derived()" << std::endl; }
};

class Derived2 : public Base
{
private:
    int m_c;

public:
    Derived2(int a, int c) : Base(a), m_c(c) {}
    virtual void func1()
    {
        std::cout << "Derived2::func1()" << std::endl;
    }
};

class Base2
{
private:
    int m_a;

public:
    Base2(int a) : m_a(a) { std::cout << "Base2::Base2()" << std::endl; }
    void func1() { std::cout << "Base2::func1()" << std::endl; }
    ~Base2() { std::cout << "Base2::~Base2()" << std::endl; }
};

class Derived3 : public Base2
{
private:
    int m_b;

public:
    Derived3(int a, int b) : Base2(a), m_b(b) { std::cout << "Derived3::Derived3()" << std::endl; }
    void func1() { std::cout << "Derived3::func1()" << std::endl; }
    ~Derived3() { std::cout << "Derived3::~Derived3()" << std::endl; }
};

int main()
{

    Base *p = new Derived(1, 2);
    // Base *p2 = new Derived2(1, 3);

    p->func1();
    // p2->func1();

    delete p;
    // 多态时的虚继承，基类的析构函数是虚函数，子类的析构函数会被调用，基类的析构函数也会被调用，
    // 但是如果基类的析构函数不是虚函数，基类的析构函数不会被调用

    std::cout << "---------------------" << std::endl;

    Derived3 *p3 = new Derived3(1, 2);

    p3->func1();

    delete p3;
    // 普通继承，基类的析构函数不是虚函数，子类和基类的析构函数都会被调用

    return 0;
}
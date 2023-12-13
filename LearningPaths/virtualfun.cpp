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

int main()
{

    Base *p = new Derived(1, 2);
    // Base *p2 = new Derived2(1, 3);

    p->func1();
    // p2->func1();

    delete p;

    return 0;
}
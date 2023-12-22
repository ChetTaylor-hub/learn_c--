/*lamada讲解使用*/

#include <iostream>

int main()
{
    // lamada表达式的基本形式
    // [捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型 {函数体}
    // [] 不捕获任何变量
    // [=] 捕获外部作用域中所有变量，并作为副本在函数体中使用
    // [&] 捕获外部作用域中所有变量，并作为引用在函数体中使用
    // [this] 捕获当前类中的this指针，让lamada表达式拥有和当前类成员函数同样的访问权限

    // lamada表达式的返回值类型推断
    // 如果lamada表达式的函数体中只有一条return语句，则该return语句的返回值类型就是lamada表达式的返回值类型
    // 如果lamada表达式的函数体中有多条return语句，则每条return语句返回值类型必须一致，且该返回值类型就是lamada表达式的返回值类型
    // 如果lamada表达式的函数体中没有return语句，则返回值类型为void

    // lamada表达式的参数列表和返回值类型可以省略
    // 如果省略了参数列表，则表示lamada表达式不接受任何参数
    // 如果省略了返回值类型，则表示lamada表达式不返回任何值

    // lamada表达式的捕获列表
    // 捕获列表是lamada表达式的重要特性，捕获列表位于参数列表之前，可以捕获外部作用域中的变量，并将其添加到lamada表达式的参数列表中
    // 捕获列表的形式如下：
    // [变量名1, 变量名2, ...]
    // [] 不捕获任何变量
    // [=] 捕获外部作用域中所有变量，并作为副本在函数体中使用
    // [&] 捕获外部作用域中所有变量，并作为引用在函数体中使用
    // [this] 捕获当前类中的this指针，让lamada表达式拥有和当前类成员函数同样的访问权限

    /*
    ！！！重要！！！
    [捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型 {函数体}
    返回一个匿名函数的指针，需要一个变量接收，然后通过这个变量调用这个匿名函数，这个变量就是函数指针
    auto 猜测匿名函数类型
    */
    int x, y;
    auto func1 = [x, &y](int a, int b) -> int
    { return a + b + x + y; };

    auto func2 = []()
    { std::cout << "hello world" << std::endl; };

    std::cout << func1(1, 2) << std::endl;
    func2();

    return 0;
}
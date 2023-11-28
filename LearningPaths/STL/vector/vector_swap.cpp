/*swap 收缩空间实例*/

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v(1000000, 1);

    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    /*
    capacity: 1000000
    size: 1000000
     */

    std::cout << "------------before swap--------------" << std::endl;
    v.resize(3);
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    /*
    ------------before swap--------------
    capacity: 1000000
    size: 3
    */

    std::cout << "------------behind swap--------------" << std::endl;
    // 调用拷贝构造函数将v赋值给新的匿名对象( std::vector<int>匿名对象(v) )，匿名对象的capacity等于v的size，互换后匿名对象被自动释放。
    std::vector<int>(v).swap(v);
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    /*
    ------------behind swap--------------
    capacity: 3
    size: 3
    */

    return 0;
}
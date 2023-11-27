# c++ STL

## 简介

C++的STL（标准模板库）是C++标准库的一个组成部分，提供了许多通用的模板类和函数，用于实现常见的数据结构和算法。STL旨在提高C++的代码重用性、可读性和灵活性。以下是STL中一些重要的组件：

1. **容器（Containers）：**
   * **向量（Vector）：** 动态数组，支持快速的随机访问。
   * **列表（List）：** 双向链表。
   * **队列（Queue）：** 队列，支持先进先出（FIFO）的操作。
   * **栈（Stack）：** 栈，支持后进先出（LIFO）的操作。
   * **集合（Set）：** 不重复元素的集合。
   * **映射（Map）：** 键-值对的集合。
2. **算法（Algorithms）：**
   * **排序（Sort）：** `sort` 函数用于排序序列。
   * **查找（Search）：** `find` 函数用于查找元素。
   * **变换（Transform）：** `transform` 函数用于对序列进行变换操作。
   * **合并（Merge）：** `merge` 函数用于合并两个有序序列。
   * **迭代器（Iterators）：** 提供了迭代器来访问容器中的元素。
3. **函数对象（Function Objects）：**
   * **谓词（Predicates）：** 可调用对象，用于在算法中定义条件。
   * **函数适配器（Function Adapters）：** `bind` 和 `function` 等适配器。
4. **迭代器（Iterators）：**
   * **输入迭代器（Input Iterators）：** 支持单次读取。
   * **输出迭代器（Output Iterators）：** 支持单次写入。
   * **前向迭代器（Forward Iterators）：** 支持单向遍历。
   * **双向迭代器（Bidirectional Iterators）：** 支持双向遍历。
   * **随机访问迭代器（Random Access Iterators）：** 支持随机访问。
5. **算法时间复杂度：**
   * 大多数STL算法都以线性对数（O(n log n)）时间运行，其中 n 是序列的大小。

👍通常迭代器作为链接容器和算法的桥梁。

STL提供了丰富的功能，可以大大简化C++程序的开发。在使用STL时，你可以遵循一些最佳实践，例如使用迭代器而非索引进行遍历，善用算法库等，以提高代码的可读性和性能。

---



## Vector

C++ 中的 `std::vector` 是标准模板库（STL）中的一个动态数组实现。它提供了动态大小的数组，支持高效的元素插入和删除。以下是关于 `std::vector` 的一些基本信息和用法：

### 包含头文件

在使用 `std::vector` 之前，需要包含 `<vector>` 头文件：

```
#include <vector>
```

### 创建和初始化

可以使用不同的方式来创建和初始化 `std::vector`。

```cpp
#include <vector>

int main() {
    // 通过初始化列表创建
    std::vector<int> vec1 = {1, 2, 3, 4, 5};

    // 通过指定大小和初始值创建
    std::vector<int> vec2(5, 10); // 包含五个元素，每个元素的值为 10

    // 默认构造函数创建空的 vector
    std::vector<int> vec3;

    return 0;
}

```

### 访问元素

可以使用索引访问 `std::vector` 的元素，索引从 0 开始。

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 访问元素
    std::cout << "Element at index 2: " << vec[2] << std::endl;

    return 0;
}

```


### 添加和删除元素

`std::vector` 提供了 `push_back` 和 `pop_back` 函数用于在尾部添加和删除元素。

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 添加元素
    vec.push_back(6);

    // 删除尾部元素
    vec.pop_back();

    // 显示 vector 中的元素
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}

```


### 迭代

可以使用迭代器遍历 `std::vector`。

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 使用迭代器遍历
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 使用范围-based for 循环
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}

```

这只是 `std::vector` 的基本用法示例。它还提供了许多其他方法和功能，包括修改元素、清空向量、获取向量大小等。详细信息可以查阅 C++ 的文档或参考相关教程。

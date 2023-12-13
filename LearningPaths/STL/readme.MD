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

## 容器

### 序列容器

#### Vector

C++ 中的 `std::vector` 是标准模板库（STL）中的一个动态数组实现。它提供了动态大小的数组，支持高效的元素插入和删除。以下是关于 `std::vector` 的一些基本信息和用法：

##### 包含头文件

在使用 `std::vector` 之前，需要包含 `<vector>` 头文件：

```
#include <vector>
```

##### 创建和初始化

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

##### 访问元素

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

##### 添加和删除元素

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

##### 迭代

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

#### list

```cpp
#include <iostream>
#include <list>

int main() {
    // 创建一个空的 list
    std::list<int> myList;

    // 在 list 尾部添加元素
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    // 在 list 头部添加元素
    myList.push_front(0);

    // 使用迭代器遍历 list
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 在指定位置插入元素
    auto it = std::find(myList.begin(), myList.end(), 2);
    if (it != myList.end()) {
        myList.insert(it, 99);
    }

    // 移除指定元素
    myList.remove(2);

    // 删除第一个元素
    myList.pop_front();

    // 删除最后一个元素
    myList.pop_back();

    // 获取 list 的大小
    std::cout << "Size: " << myList.size() << std::endl;

    // 判断 list 是否为空
    if (myList.empty()) {
        std::cout << "List is empty." << std::endl;
    } else {
        std::cout << "List is not empty." << std::endl;
    }

    return 0;
}

```

#### deque

```cpp
#include <iostream>
#include <deque>

int main() {
    // 创建一个空的 deque
    std::deque<int> myDeque;

    // 在 deque 尾部添加元素
    myDeque.push_back(1);
    myDeque.push_back(2);
    myDeque.push_back(3);

    // 在 deque 头部添加元素
    myDeque.push_front(0);

    // 使用迭代器遍历 deque
    for (auto it = myDeque.begin(); it != myDeque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 在指定位置插入元素
    auto it = std::find(myDeque.begin(), myDeque.end(), 2);
    if (it != myDeque.end()) {
        myDeque.insert(it, 99);
    }

    // 删除指定元素
    myDeque.erase(std::remove(myDeque.begin(), myDeque.end(), 2), myDeque.end());

    // 删除第一个元素
    myDeque.pop_front();

    // 删除最后一个元素
    myDeque.pop_back();

    // 获取 deque 的大小
    std::cout << "Size: " << myDeque.size() << std::endl;

    // 判断 deque 是否为空
    if (myDeque.empty()) {
        std::cout << "Deque is empty." << std::endl;
    } else {
        std::cout << "Deque is not empty." << std::endl;
    }

    return 0;
}

```

#### queue

```cpp
#include <iostream>
#include <queue>

int main() {
    // 创建一个空的队列
    std::queue<int> myQueue;

    // 入队
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // 查看队头元素
    std::cout << "Front: " << myQueue.front() << std::endl;

    // 出队
    myQueue.pop();

    // 再次查看队头元素
    std::cout << "Front after pop: " << myQueue.front() << std::endl;

    // 获取队列的大小
    std::cout << "Size: " << myQueue.size() << std::endl;

    // 判断队列是否为空
    if (myQueue.empty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    return 0;
}

```

#### stack

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;

    // 使用push接口添加元素
    s.push(1);
    s.push(2);
    s.push(3);

    // 使用top接口访问栈顶元素
    std::cout << "Top: " << s.top() << std::endl;

    // 使用empty和size接口检查栈是否为空以及栈的大小
    std::cout << "Is empty: " << (s.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size: " << s.size() << std::endl;

    // 使用pop接口移除栈顶元素
    s.pop();
    std::cout << "Top after pop: " << s.top() << std::endl;

    return 0;
}

```


### 关联容器

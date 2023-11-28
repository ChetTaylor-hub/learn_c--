#include <iostream>
#include "MyVector.hpp"

int main()
{

    MyVector<int> array;
    for (int i = 0; i < 10; i++)
    {
        array.push_back(i * i);
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << array[i] << std::endl;
    }

    return 0;
}
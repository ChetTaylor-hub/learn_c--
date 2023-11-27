#pragma once
#include <iostream>

template <class T>
class MyVector
{
private:
    struct array
    {
        T Val;
        array *Next;
        array *Pre;
        array(T val) : Val(val), Next(nullptr), Pre(nullptr) {}
    };

public:
    MyVector();
    ~MyVector();
    void push_back(T val);
    T pop();
    void delet(int index);
    int size();
    bool empty();
    T operator[](int index);
    MyVector<T> slice(int start, int end);

private:
    int len;
    array *head;
    array *tag;
};

template <class T>
MyVector<T>::MyVector()
{
    len = 0;
    head = nullptr;
    tag = nullptr;
}

template <class T>
void MyVector<T>::push_back(T val)
{
    if (!len)
    {
        array *tmp = new array(val);
        head = tmp;
        tag = tmp;
        len++;
        return;
    }

    array *tmp = new array(val);
    tag->Next = tmp;
    tmp->Pre = tag;
    tag = tmp;
    len++;
    return;
}
template <class T>
T MyVector<T>::pop()
{
    T tmpVal = tag->Val;
    array *tmp = tag;
    tag = tag->Pre;
    tag->Next = nullptr;
    delete tmp;
    tmp = nullptr;
    len--;
    return tmpVal;
}

template <class T>
int MyVector<T>::size()
{
    return len;
}

template <class T>
bool MyVector<T>::empty()
{
    return true ? len == 0 : false;
}
template <class T>
T MyVector<T>::operator[](int index)
{
    array *tmp = head;
    for (int i = 0; i < index; i++)
        tmp = tmp->Next;

    return tmp->Val;
}

template <class T>
void MyVector<T>::delet(int index)
{
    if (index < 0 || index >= len)
    {
        std::cout << "index error !" << std::endl;
        return;
    }

    array *tmp = head;
    for (int i = 0; i < index; i++)
        tmp = tmp->Next;
    // 判断是否是最后 -个元素
    if (!tmp->Next)
    {
        pop();
        return;
    }

    // 若不是最后个元素
    tmp->Pre->Next = tmp->Next;
    tmp->Next->Pre = tmp->Pre;
    delete tmp;
    len--;
    tmp = nullptr;
}

template <class T>
MyVector<T> MyVector<T>::slice(int start, int end)
{
    MyVector<T> sliceMyVector;
    if (start < 0)
        start = len + start;
    if (end < 0)
        end = end + len;
    if (start > len || end > len)
    {
        std::cout << "slice index error !" << std::endl;
        return sliceMyVector;
    }

    if (start <= end)
    {
        array *tmp = head;
        for (int i = 0; i < start; i++)
            tmp = tmp->Next;
        for (int i = start; i < end; i++)
        {
            sliceMyVector.push_back(tmp->Val);
            tmp = tmp->Next;
        }
        return sliceMyVector;
    }
    else
    {
        array *tmp = head;
        for (int i = 0; i < start; i++)
            tmp = tmp->Next;
        for (int i = start; i > end; i--)
        {
            sliceMyVector.push_back(tmp->Val);
            tmp = tmp->Pre;
        }

        return sliceMyVector;
    }
}

template <class T>
MyVector<T>::~MyVector()
{
    array *tmp = head;
    while (head)
        head = head->Next;
    delete tmp;
    tmp = head;
    tag = nullptr;
    tmp = nullptr;
}

#pragma once
#include <iostream>
#include "Person.h"
#include "Employee.h"

class WorkSpace
{
private:
    Employee employee;

public:
    WorkSpace(/* args */);
    ~WorkSpace();

    void Display();
    void Exit();
    void AddOne();
    void DeleteOne();
    void FindOne();
    void SortAll();
    void DisplayAll();
    void EditOne();
    void ClearAll();
};

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

class Employee
{
public:
    struct Person
    {
        int Id;
        std::string Name;
        std::string Posts;
        Person(int id, std::string name, std::string posts) : Id(id), Name(name), Posts(posts) {}
    };
    Employee();
    ~Employee();
    std::vector<Person> readEmployee();
    void writeEmployee();
    void addEmployee(int id, std::string name, std::string posts);
    void deleteEmployee();
    void deleteEmployee(int id);
    void deleteEmployee(std::string name);
    void findEmployee(int id);
    void findEmployee(std::string name);
    void sortEmployee(int mode);
    void editEmployee(int id, std::string name, std::string posts);

    bool checkId(int id);

private:
    std::ifstream m_input;
    std::ofstream m_output;
    std::string m_path;

    std::vector<Person> persons;
};

bool compare(Employee::Person p1, Employee::Person p2);
bool compare2(Employee::Person p1, Employee::Person p2);

#include "Employee.h"

Employee::Employee() : m_path("employee.txt")
{
}

Employee::~Employee()
{
}

std::vector<Employee::Person> Employee::readEmployee()
{
    persons.clear();

    m_input.open(m_path, std::ios::in);
    if (!m_input.is_open())
    {
        m_output.open(m_path, std::ios::out);
        std::cerr
            << m_path << "打开失败！" << std::endl;
    }
    else
    {
        std::string line;
        while (std::getline(m_input, line))
        {
            std::istringstream iss(line);
            std::string name, posts;
            int id;

            // 读取
            iss >> id >> name >> posts;
            persons.push_back(Person(id, name, posts));
        }

        m_input.close();

        return persons;
    }
}

void Employee::writeEmployee()
{
    m_output.open(m_path, std::ios::out);
    if (!m_output.is_open())
    {
        std::cerr << m_path << "打开失败！" << std::endl;
    }
    else
    {
        for (int i = 0; i < persons.size(); i++)
            m_output << persons[i].Id << " " << persons[i].Name << " " << persons[i].Posts << std::endl;
        m_output.close();
    }
}

void Employee::addEmployee(int id, std::string name, std::string posts)
{
    readEmployee();
    Person person(id, name, posts);
    persons.push_back(person);
    writeEmployee();
}

void Employee::deleteEmployee(int id)
{
    readEmployee(); // 先读取员工信息

    for (int i = 0; i < persons.size(); ++i)
    {
        if (persons[i].Id == id)
        {
            persons.erase(persons.begin() + i);
        }
    }

    writeEmployee();
}

void Employee::deleteEmployee(std::string name)
{
    readEmployee();

    for (int i = 0; i < persons.size(); ++i)
    {
        if (persons[i].Name == name)
        {
            persons.erase(persons.begin() + i);
        }
    }

    writeEmployee();
}

void Employee::deleteEmployee()
{
    readEmployee();
    persons.clear();
    writeEmployee();
}

void Employee::findEmployee(int id)
{
    readEmployee(); // 先读取员工信息

    for (int i = 0; i < persons.size(); ++i)
    {
        if (persons[i].Id == id)
        {
            std::cout << "查找结果：" << std::endl;
            std::cout << "编号：" << persons[i].Id << " 姓名：" << persons[i].Name << " 职位：" << persons[i].Posts << std::endl;
        }
    }
}

void Employee::findEmployee(std::string name)
{
    readEmployee(); // 先读取员工信息

    for (int i = 0; i < persons.size(); ++i)
    {
        if (persons[i].Name == name)
        {
            std::cout << "查找结果：" << std::endl;
            std::cout << "编号：" << persons[i].Id << " 姓名：" << persons[i].Name << " 职位：" << persons[i].Posts << std::endl;
        }
    }
}

void Employee::sortEmployee(int mode)
{
    readEmployee();
    if (mode == 1)
    {
        std::sort(persons.begin(), persons.end(), compare);
    }
    else
    {
        std::sort(persons.begin(), persons.end(), compare2);
    }
}

void Employee::editEmployee(int id, std::string name, std::string posts)
{
    readEmployee();
    for (int i = 0; i < persons.size(); i++)
    {
        if (id == persons[i].Id)
        {
            persons[i].Name = name;
            persons[i].Posts = posts;
            std::cout << "修改成功！" << std::endl;
        }
    }
    writeEmployee();
}

bool Employee::checkId(int id)
{
    readEmployee();
    for (int i = 0; i < persons.size(); i++)
    {
        if (id == persons[i].Id)
        {
            std::cout << "Id：" << id << " 已存在！" << std::endl;
            return true;
        }
    }
    std::cout << "查无此人！" << std::endl;
    return false;
}

// 升序
bool compare(Employee::Person p1, Employee::Person p2)
{
    return p1.Id < p2.Id;
}

bool compare2(Employee::Person p1, Employee::Person p2)
{
    return p1.Id > p2.Id;
}
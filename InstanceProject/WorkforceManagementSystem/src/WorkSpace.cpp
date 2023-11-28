#include "WorkSpace.h"

WorkSpace::WorkSpace(/* args */)
{
}

WorkSpace::~WorkSpace()
{
}

void WorkSpace::Display()
{
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "--------这是一个员工管理系统------------" << std::endl;
    std::cout << "-------------0 退出系统----------------" << std::endl;
    std::cout << "-------------1 添加员工信息------------" << std::endl;
    std::cout << "-------------2 删除员工信息------------" << std::endl;
    std::cout << "-------------3 显示员工信息------------" << std::endl;
    std::cout << "-------------4 查找员工信息------------" << std::endl;
    std::cout << "-------------5 员工序号排序------------" << std::endl;
    std::cout << "-------------6 修改员工信息------------" << std::endl;
    std::cout << "-------------7 清除所有信息------------" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

// 0 退出系统
void WorkSpace::Exit()
{
    std::cout << "退出系统" << std::endl;
    std::system("pause");
    std::exit(-1);
}

// 1 添加员工信息
void WorkSpace::AddOne()
{
    int id;
    std::string name;
    std::string posts;

    std::cout << "要添加几位员工：" << std::endl;
    int number;
    std::cin >> number;

    for (int i = 0; i < number; ++i)
    {
        std::cout << "请添加第" << i + 1 << "员工的编号：" << std::endl;
        std::cin >> id;
        if (!employee.checkId(id))
        {
            std::cout << "请添加第" << i + 1 << "员工的姓名：" << std::endl;
            std::cin >> name;
            std::cout << "请添加第" << i + 1 << "员工的职位：" << std::endl;
            std::cin >> posts;
            employee.addEmployee(id, name, posts);
        }
        else
        {
            i--;
        }
    }
}

// 2 删除员工信息
void WorkSpace::DeleteOne()
{
    int mode;
    std::cout << "请选择一种删除方式：" << std::endl;
    std::cout << "按编号删除：1" << std::endl;
    std::cout << "按姓名删除：2" << std::endl;
    std::cin >> mode;
    if (mode == 1)
    {
        int id;
        std::cout << "请输入员工编号：" << std::endl;
        std::cin >> id;
        if (employee.checkId(id))
            employee.deleteEmployee(id);
    }
    else if (mode == 2)
    {
        std::string name;
        std::cout << "请输入员工姓名：" << std::endl;
        std::cin >> name;
        employee.deleteEmployee(name);
    }
    else
    {
        std::cout << "请选择正确删除方式：" << std::endl;
    }
}

// 3 显示员工信息
void WorkSpace::DisplayAll()
{
    std::vector<Employee::Person> persons = employee.readEmployee();
    if (persons.empty())
    {
        std::cout << "员工信息为空" << std::endl;
    }
    else
    {
        for (int i = 0; i < persons.size(); i++)
            std::cout << "编号：" << persons[i].Id << "\t姓名：" << persons[i].Name << "\t职位：" << persons[i].Posts << std::endl;
    }
}

// 4 查找员工信息
void WorkSpace::FindOne()
{
    int mode;
    std::cout << "请选择一种查找方式：" << std::endl;
    std::cout << "按编号查找：1" << std::endl;
    std::cout << "按姓名查找：2" << std::endl;
    std::cin >> mode;
    if (mode == 1)
    {
        int id;
        std::cout << "请输入员工编号：" << std::endl;
        std::cin >> id;
        if (employee.checkId(id))
            employee.findEmployee(id);
    }
    else if (mode == 2)
    {
        std::string name;
        std::cout << "请输入员工姓名：" << std::endl;
        std::cin >> name;
        employee.findEmployee(name);
    }
    else
    {
        std::cout << "请选择正确删除方式：" << std::endl;
    }
}

// 5 员工序号排序
void WorkSpace::SortAll()
{

    std::cout << "请选择一种排序方式：" << std::endl;
    std::cout << "按升序排序：1" << std::endl;
    std::cout << "按降序排序：2" << std::endl;
    int mode;
    std::cin >> mode;
    if (mode == 1 || mode == 2)
    {
        employee.sortEmployee(mode);
        employee.writeEmployee();
    }
    else
    {
        std::cout << "请选择正确排序方式：" << std::endl;
    }
}

// 6 修改员工信息
void WorkSpace::EditOne()
{
    std::cout << "请选择修改几号员工的信息：" << std::endl;
    int id;
    std::cin >> id;
    if (employee.checkId(id))
    {
        std::cout << "请输入修改后的姓名：" << std::endl;
        std::string name;
        std::cin >> name;
        std::cout << "请输入修改后的职位：" << std::endl;
        std::string posts;
        std::cin >> posts;
        employee.editEmployee(id, name, posts);
    }
}
// 7 清除所有信息
void WorkSpace::ClearAll()
{
    employee.deleteEmployee();
}
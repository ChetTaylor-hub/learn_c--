/* 输入输出运算符重载.cpp */
/*
   有一销售人员类Sales，其数据成员有姓名name，身份证号id，年龄age。
   重载输入/输出运算符实现对Sales类数据成员的输入和输出。
 */
#include <cstring>
#include <iostream>
using namespace std;
class Sales
{
private:
    char name[10];
    char id[18];
    int age;

public:
    Sales(char *Name, char *ID, int Age);

    friend ostream &operator<<(ostream &os, Sales &s); // 重载输出运算符
    friend istream &operator>>(istream &is, Sales &s); // 重载输入运算符
};
Sales::Sales(char *Name, char *ID, int Age)
{
    strcpy(name, Name);
    strcpy(id, ID);
    age = Age;
}
ostream &operator<<(ostream &os, Sales &s)
{
    os << s.name << "\t"; // 输出姓名
    os << s.id << "\t";   // 输出身份证号
    os << s.age << endl;  // 输出年龄
    return os;
}
istream &operator>>(istream &is, Sales &s)
{
    // cout << "cin name, id, age" << endl;
    is >> s.name >> s.id >> s.age;
    return is;
}
int main()
{
    Sales s1("dukang", "214198012111711", 40); // L1
    Sales s2();
    cout << s1;   // L2
    cout << endl; // L3
    cin >> s1;    // L4

    cout << s1; // L5
}
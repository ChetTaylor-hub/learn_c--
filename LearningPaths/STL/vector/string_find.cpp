/*string 查找子串实例*/

#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> strlist;
    strlist.push_back("chentao@163.com");
    strlist.push_back("lisi@163.com");
    strlist.push_back("zhangsan@163.com");
    strlist.push_back("wangwu@163.com");

    for (std::vector<std::string>::iterator i = strlist.begin(); i != strlist.end(); i++)
    {
        std::cout << (*i).substr(0, (*i).find("@")) << std::endl;
    }

    return 0;
}
#pragma once
#include <iostream>
#include <string>

class Person
{
private:
    std::string m_name;
    int m_id;
    std::string m_posts;

public:
    Person(int id, std::string name, std::string posts);
    ~Person();
    std::string getName();
    std::string getPosts();
    int getId();
};

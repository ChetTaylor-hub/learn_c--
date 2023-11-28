#include "Person.h"

Person::Person(int id, std::string name, std::string posts)
    : m_name(name), m_id(id), m_posts(posts)
{
}

Person::~Person()
{
}

std::string Person::getName()
{
    return m_name;
}
std::string Person::getPosts()
{
    return m_posts;
}
int Person::getId()
{
    return m_id;
}
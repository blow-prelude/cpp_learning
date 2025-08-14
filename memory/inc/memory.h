#ifndef MOMORY_H
#define MOMORY_H

#include <iostream>
#include <string>
class Student
{
public:
    Student(int age, std::string name) : _age(age), _name(name)
    {
        std::cout << "Student constructor" << "age: " << _age << std::endl;
    }
    ~Student()
    {
        std::cout << "Student destructor" << "age: " << _age << std::endl;
    }

    void get_age()
    {
        std::cout << "student age: " << _age << std::endl;
    }

private:
    int _age;
    std::string _name;
};

// 自定义删除器，适用仿函数实现
class FileDeleter
{
public:
    // 重载()运算符
    void operator()(FILE *fp) const
    {
        if (fp)
        {
            std::cout << "file closed successfully" << std::endl;
            fclose(fp);
        }
    }
};
#endif
#ifndef CLASS_A
#define CLASS_A
#include <iostream>
#include <memory>

// 前向声明即可
// 如果需要访问B的成员变量或者成员函数，也是前向声明，具体实现在cpp文件中,并include ClassB
class B;

class A
{
public:
    //
    std::weak_ptr<B> point_to_b;
    A()
    {
        std::cout << "Instructor A" << std::endl;
    }
    ~A()
    {
        std::cout << "Destructor A" << std::endl;
    }
};

#endif
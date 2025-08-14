#ifndef CLASS_B
#define CLASS_B

#include <iostream>
#include <memory>

class A;

class B
{
public:
    std::shared_ptr<A> point_to_a;
    B()
    {
        std::cout << "Instructor B" << std::endl;
    }
    ~B()
    {
        std::cout << "Destructor B" << std::endl;
    }
};
#endif
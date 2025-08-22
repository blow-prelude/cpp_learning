#ifndef TEMPLATE
#define TEMPLATE

#include <iostream>
#include <string>
#include <vector>
#include <list>
// 有些通用模板无法满足需求的时候，可以特化模板处理特定的情况
// 包括全特化和偏特化，函数模板只支持全特化

// 模板不能像普通类那样分离编译特性，声明和实现需要在同一个头文件中
// 全特化就是完全特定的类型组合
// 通用类模板
template <typename T>
class Printer
{
public:
    void print(const T &obj)
    {
        std::cout << "general printer:" << obj << std::endl;
    }
};

// 类模板全特化,特化一个专门支持string类型的模板
template <>
class Printer<std::string>
{
public:
    void print(const std::string &obj)
    {
        std::cout << "string printer:" << obj << std::endl;
    }
};

// 偏特化就是对部分模板参数进行特定的类型处理，保持其他参数的通用性
// 通用类模板
template <typename T, typename U>
class Pair2
{
public:
    T first;
    U second;

    Pair2(T a, U b) : first(a), second(b) {}

    void print() const
    {
        std::cout << "general pair: " << first << ',' << second << std::endl;
    }
};

// 偏特化，当第二个参数是指针时，上面的通用模板只能打印地址，这不是所期待的，需要解引用，因此需要特化
template <typename T, typename U>
class Pair2<T, U *>
{
public:
    T first;
    U *second;

    Pair2(T a, U *b) : first(a), second(b) {}

    void print() const
    {
        std::cout << "general pair: " << first << ',' << *second << std::endl;
    }
};

// 变参模板使用参数包，可以接受可变数量的参数
// 在c++17之前，需要通过递归的方式处理参数包，原理是每次从参数包里取出第一个参数，然后将剩下的放入下一轮使用，以此类推
// 当所有参数都取出的时候，参数包为空，就不会调用有参数的递归情况，而是调用无参数的情况，   所以这需要实现2个函数

// 基础情况，即无参数
void print_all()
{
    std::cout << std::endl;
}
// 递归情况
// 参数包在声明的时候需要在变量前面加上... ，在使用的时候在变量后面加上...
template <typename T, typename... Args>
void print_all(const T &first, const Args &...args)
{
    std::cout << first << ",";
    print_all(args...);
}

// c++17引入折叠表达式
template <typename... Args>
void cout_all(const Args &...args)
{

    // 内层：第一个括号内是每次都需要执行的操作， ... 表示重复该操作
    // 最后用一个外层的括号括住所有内容，形成一个合法的表达式
    ((std::cout << args << ","), ...);
    std::cout << std::endl;
}

// 不指定初始值的是一元折叠表达式，指定初始值的是二元折叠表达式
// 一元右折叠  (pack op ...)
// 二元左折叠  (init op ... op pack)
// 上述模型中，pack表示参数包，op表示操作符，init表示初始值

template <typename... Args>
auto substract_right_fold(const Args &...args) -> decltype((... - args))
{
    // a-(b-(c-d))
    return (args - ...);
}

template <typename... Args>
auto substract_left_fold(const Args &...args) -> decltype((args - ...))
{
    // ((a-b)-c)-d
    return (... - args);
}

// 示例：模板+折叠表达式
struct Point
{
    int x, y;
    // 重载+运算符
    Point operator+(const Point &other) const
    {
        return Point{x + other.x, y + other.y};
    }
};

template <typename... Args>
auto my_sum(const Args &...args) -> decltype((args + ...))
{
    return (args + ...);
}

#endif
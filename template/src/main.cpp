
#include "../inc/template.h"

// 模板的模板参数主要包类型参数、非类型参数、模板模板参数
// 类型参数在模板实例化的时候会被具体的类型替代 ， 非类型参数则接受值比如整数、指针等
// 模板模板参数就是将一个模板作为模板参数，相当于是模板的嵌套

// 函数模板
template <typename T>
T max_value(T a, int b)
{
    return (a > b) ? a : b;
}

template <typename T, int N>
T get_biggest(T t)
{
    return (t > N) ? t : N;
}
// 类模板
template <typename T, typename U>
class Pair
{
public:
    T first;
    U second;

    Pair(T a, U b) : first(a), second(b) {}

    void print() const
    {
        std::cout << "Pair:" << first << ',' << second << std::endl;
    }
};

template <template <typename, typename> class Container, typename T>
class ContainerPrinter
{
public:
    void print(const Container<T, std::allocator<T>> &container)
    {
        for (const T &elem : container)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    /*
    // int ,double ,char 类型在编译过程中自动推导
    std::cout << "max value :" << max_value(20, 25) << std::endl;
    // 显式指定类型
    std::cout << "max value :" << max_value<double>(2.73, 3.14) << std::endl;
    std::cout << "max value :" << max_value('a', 'c') << std::endl;

    std::cout << "bigger value :" << get_biggest<int, 3>(4) << std::endl;

    Pair<int, double> p1(21, 32.2);
    p1.print();

    Pair<std::string, float> p2("pi", 3.14);
    p2.print();

    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<int> lst = {6, 7, 8, 9};

    ContainerPrinter<std::vector, int> vec_printer;
    vec_printer.print(vec);

    ContainerPrinter<std::list, int> list_priner;
    list_priner.print(lst);
    */

    /*
    Printer<int> int_printer;
    int_printer.print(4);
    Printer<std::string> str_printer;
    str_printer.print("hello template");

    double pi = 3.14;
    Pair2<int, double> p1(21, pi);
    p1.print();
    // 编译器再推导模板参数的时候优先寻找更具体地匹配，而偏特化只匹配第二个参数为指针地情况，更具体，所以自动选择偏特化版本
    Pair2<std::string, double *> p2("pi", &pi);
    p2.print();
    */

    print_all(1, 2.2, 'c', "hello");
    cout_all(2, 4.3, "world");

    std::cout << "left fold: " << substract_left_fold(5, 4, 3, 2, 1) << std::endl;
    std::cout << "right fold: " << substract_right_fold(5, 4, 3, 2, 1) << std::endl;
    Point p1{1, 2}, p2{2, 3}, p3{3, 4};
    auto sum_int = my_sum(2, 3, 4);
    auto sum_point = my_sum(p1, p2, p3);
    std::cout << sum_int << std::endl;
    std::cout << sum_point.x << " " << sum_point.y << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// 重载函数，允许一个文件里定义多个同名函数，但是参数不同，调用时通过参数及其类型就能确定具体要调用哪个
/*
int add(int a,int b){
    return a+b;
}

int add(double a,double b,double c=1.0){
    return a+b+c;
}

void add(){
    std::cout<<"add"<<std::endl;
}
*/
// 函数可以有默认参数，但是默认参数需要放在右边
// 默认参数只要在声明时填入即可

// 内联函数，在函数声明前加上inline关键字，建议编译器把代码直接在函数调用处展开，减小开销

// 指向数组的指针
int array[5] = {1, 2, 3, 4, 5};
int (*parray)[5] = &array;

// 函数指针
int (*padd)(int, int);
// 普通函数
int add(int a, int b)
{
    return a + b;
}

int substract(int a, int b)
{
    return a - b;
}
// 函数指针可以作为参数，传递给其他函数

int caculate(int (*padd)(int, int), int c, int d)
{
    int res = padd(c, d);
    return res;
}

// 仿函数，就是把一个类对象重载了()，使其可以像函数一样被调用
// 仿函数的优势是可以保存状态（依赖于成员变量），可以进行复杂操作，并且由于其可以被编译器优化，使用性能敏感的代码
// 仿函数可以和模板结合，实现高度通用的代码
class IsBiggerThan
{
private:
    int threshold;

public:
    IsBiggerThan(int t) : threshold(t) {}

    // 重载运算符 ()
    bool operator()(int x) const
    {
        return x > threshold;
    }
};

struct Multiply
{
    int operator()(int a, int b)
    {
        return a * b;
    }
};

class Math
{
public:
    int power(int base, int expr)
    {
        int res = 1;
        for (int i = 0; i < expr; i++)
        {
            res *= base;
        }
        return res;
    }
};

int main()
{
    /*
    int a=add(3,5);
    double b=add(2.1,5.3);
    std::cout<<a<<std::endl;
    add();
    */

    /*
    // lambda函数
    //  组件：        [捕获列表]（参数列表 ）-> 返回类型可省略{}
    // 可以捕获值，也可以捕获引用
    int sum = 0;
    int *psum = new int(0);
    std::vector numbers = {10, 20, 30, 40};
    // for_each会生成一个迭代器，对每个元素执行一个一元函数的操作
    std::for_each(numbers.begin(), numbers.end(), [&sum](int n)
                  { sum += n; });
    std::cout << "sum = " << sum << std::endl;
    std::for_each(numbers.begin(), numbers.end(), [psum](int n)
                  { *psum += n; });
    std::cout << "*psum = " << *psum << std::endl;
    delete (psum);
    */

    /*
    // 函数名和函数地址等价，指向同一片内存，和数组名、数组地址的关系相同
    padd = add;
    // int a = padd(3, 4);
    int a = caculate(padd, 3, 4);
    std::cout << a << std::endl;
    */

    /*
    std::vector<int> num_ver = {1, 23, 52, 76, 85};
    int thresold = 50;
    IsBiggerThan bigger_than_thresold = IsBiggerThan(thresold);
    // find_if 是一个标准库的算法，迭代器迭代，会返回第一个返回值为true的指针，如果没有返回值为true的则返回尾指针
    auto it = std::find_if(num_ver.begin(), num_ver.end(), bigger_than_thresold);
    if (it != num_ver.end())
    {
        std::cout << "found it: " << *it << std::endl;
    }
    else
    {
        std::cout << "not found" << std::endl;
    }
    */

    /*
    // 普通函数，仿函数，lambda表达式都可以称之为 function 对象
    // 下面这行代码表示初始化一个容器，每个元素都是function对象，这些对象都返回值为int,需要2个int类型的参数
    std::vector<std::function<int(int, int)>> funcs;
    funcs.emplace_back(add);
    funcs.emplace_back(Multiply());
    funcs.emplace_back([](int a, int b) -> int
                       { return a - b; });

    for (auto &p : funcs)
    {
        std::cout << "results = " << p(4, 3) << std::endl;
    }
    */

    // bind可绑定可调用对象的部分参数，生成新的可调用对象
    // std::placeholders表示占位符,_1表示新生成的可调用对象的第一个需要占位的参数位置，以此类推
    auto new_substract = std::bind(substract, 3, std::placeholders::_1);
    std::cout << "new substract in bind :" << new_substract(2) << std::endl;
    // 同样的操作lambda表达式也可以实现
    // 无论是bind绑定还是lambda捕获，都要注意对象的生命周期
    auto add_with_2_lambda = [](int b) -> int
    {
        return add(2, b);
    };
    std::cout << "a param add with 2 in lambda:" << add_with_2_lambda(5) << std::endl;

    // 绑定成员函数,第一个需要传该成员函数的地址，第二个需要传该对象的地址
    // 这是因为，成员函数的第一个隐藏参数是其属于的类对象的地址
    Math math = Math();
    auto power_of_2 = std::bind(&Math::power, &math, 2, std::placeholders::_1);
    std::cout << "2^param = " << power_of_2(4) << std::endl;

    // 也可以绑定静态成员函数
    return 0;
}
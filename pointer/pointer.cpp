#include <iostream>

void swap(int &a, int &b)
{
    // 函数通过传参把值传给引用，在函数中对引用进行处理，也就实现了对变量本身的操作
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    // 引用和变量本身指向同一个地址，因此改变引用，变量本身也会改动，反之同理
    /*
    int a = 10;
    int &b = a;
    std::cout<< "a=" << a << std::endl;
    std::cout<< "b=" << b << std::endl;
    b = 20;
    std::cout<< "a=" << a << std::endl;
    std::cout<< "b=" << b << std::endl;
    */
    // 引用必须被初始化，不可被修改； 且没有空引用

    /*
    int a = 1;
    int b = 2;
    swap(a,b);
    std::cout<< "a=" << a << std::endl;
    std::cout<< "b=" << b << std::endl;
    swap2(&a,&b);
    std::cout<< "a=" << a << std::endl;
    std::cout<< "b=" << b << std::endl;
    */

    // 左值指的是表达式左边的值，一般具有持久状态
    // 相对的，右值往往会立即销毁

    // 左值引用，对一个已有的对象创建引用
    // int &a=...;
    // 右值引用，对一个临时对象创建引用,可以对右值进行复杂操作
    // int && a =...;

    // 引用内部是通过指针来完成的，但是又有区别
    // 指针本身是一个对象，需要内存为其分配地址,而引用只是一个别名，和被引用的对象占用同一个内存单元
    // 指针可以不被初始化，可以改变指向

    // 空指针
    // int *p = nullptr;     //最新版本写法
    // int *p2 = 0;
    // int *p3 = NULL;

    // 对const的引用，又称之为常量引用
    // 常量引用用来绑定常量，且不可以修改引用的值

    // 指向常量的指针（point to const）, 不能修改其指向的对象的值   因此想要存放常量对象的地址，需要point to const
    // const double PI = 3.14;
    // const double* p = &PI;
    // 常量指针（const pointer）,不能改变指向对象，但是指向内容可以修改
    //  int* const p = 3;
    // 记忆：const后面紧邻的不可被修改

    // 顶层const和底层const

    // 常量表达式,即在编译阶段就能得到计算结果的表达式，无需到运行阶段计算。  ，用constexpr修饰
    // constexpr int x = 10;
    // 可以用constexpr 修饰指针，且只对指针起作用，但是初始化时只能是空指针或者指向有固定地址的对象（全局区里存放的对象）
    // constexpr int *p    相当于    int* const p

    return 0;
}
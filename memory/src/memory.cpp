#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <memory>
#include "../inc/memory.h"
#include "../inc/ClassA.h"
#include "../inc/ClassB.h"

int main()
{
    /*
    // C风格的内存管理
    // malloc开辟内存，返回值是void*，需要强制转换
    // free释放内存
    int *p = (int *)malloc(sizeof(int));
    // 检测是否分配了内存，如果没有分配内存，返回值为空指针
    if (p == NULL)
    {
        std::cerr << "malloc failed" << std::endl;
        return -1;
    }
    *p = 10;
    std::cout << "p = " << *p << std::endl;
    // 释放内存
    free(p);

    // 也可以创建数组
    int *parr = (int *)malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
    {
        parr[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << "parr[" << i << "] = " << parr[i];
    }
    std::cout << std::endl;
    free(parr);

    // C++风格的内存管理
    //  new开辟内存，返回值是指针，不需要强制转换
    int *parray = new int[10]; // 创建一个int类型的数组，大小为10
    delete[] parray;

    // C++风格的开辟和释放内存会调用对象的构造函数和析构函数，而C风格不会
    // C风格开辟失败会返回空指针，而cpp会抛出异常，但是可以指定new使其开辟失败也返回空指针，就和c的处理方式一致
    Student *stu1 = new (std::nothrow) Student(18, "wtr");
    if (stu1 == nullptr)
    {
        std::cout << "failed to new memory" << std::endl;
    }

    Student *pstu_arr = new Student[3]{
        {18, "wtr"},
        {19, "wjx"},
        {20, "msy"}};

    delete stu1;
    delete[] pstu_arr;
    */

    /*
    // 使用realloc进行内存重分配,返回的是重新分配的内存块的起始地址
    try
    {
        int *origin_ptr = (int *)malloc(sizeof(int));

        std::cout << "address of origin pointer: " << origin_ptr << std::endl;
        origin_ptr = (int *)realloc(origin_ptr, sizeof(int) * 3);
        std::cout << "address of realloc pointer: " << origin_ptr << std::endl;
        // 如果想要操作内存块的其他空间，需要另外申请一个指针
        int *ptr = origin_ptr;
        *(++ptr) = 5;
        // 一定要释放开辟的内存块的起始地址
        free(origin_ptr);
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "bad alloc: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "visit out of range: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    */

    /*
    // 原生指针可能会因为多线程、生命周期不同而引发的内存泄漏、悬垂指针、双重释放的问题
    // 而智能指针，体现RAII思想即 资源获取即初始化，利用局部对象自动销毁的特性控制资源的生命周期

    // 智能指针可以像原生指针一样解引用，得到指向的对象

    // unique_ptr,任何时候只用一个该智能指针的实例拥有某个对象的所有权，只能够移动不可拷贝
    // 2种构造方法，后者更异常安全且开销小，这是因为前者先new一块空间，然后再为指针开辟一片空间，而后者直接为指针开辟空间
    // 前者如果开辟失败，那么new出来的内存无法被释放，导致内存泄漏
    std::unique_ptr<Student> unique_stu1(new Student(18, "wts"));
    unique_stu1->get_age();
    auto unique_stu2 = std::make_unique<Student>(29, "jaba");
    unique_stu2->get_age();
    // 移动语义
    std::unique_ptr<Student> unique_stu3 = std::move(unique_stu1);
    if (!unique_stu1)
    {
        std::cout << "unique_stu1 is now nullptr" << std::endl;
    }
    unique_stu3->get_age();
    // 释放unique_stu2指向的对象，并指向一个新的对象
    unique_stu2.reset(new Student(19, "wtr"));
    unique_stu2->get_age();
    */

    /*
    // shared_ptr 内部维护一块空间，一个指针指向所管理的数据的地址，还有一个是指向控制块的指针，控制块包括强引用计数、弱引用计数、删除器、分配器
    // 当进行赋值操作的时候，先把旧的引用计数-1，如果引用计数为0，则释放旧的shared_ptr； 然后拷贝新的数据指针和引用计数指针，并+1引用计数
    auto shared_stu1 = std::make_shared<Student>(19, "wtr");
    std::cout << "use count : " << shared_stu1.use_count() << std::endl;
    {
        // 调用拷贝构造
        std::shared_ptr<Student> shared_stu2 = shared_stu1;
        std::cout << "use_count : " << shared_stu1.use_count() << std::endl;
    }
    */

    /*
    // weak_ptr 适用于观察者模式，因为它虽然没有 其指向的 shared_ptr 所管理的对象 的所有权，但是可以转化成 shared_ptr
    std::shared_ptr<int> sp1 = std::make_shared<int>(11);
    std::weak_ptr<int> wp = sp1;
    std::cout << "before lock, use count: " << sp1.use_count() << std::endl;
    // 需要检查所指对象是否被释放，如果没有返回false
    if (!wp.expired())
    {
        std::shared_ptr<int> sp2 = wp.lock();
        std::cout << "after lock ,use count : " << sp1.use_count() << std::endl;
        // weak_ptr 的use_count 就是强引用计数
        std::cout << "after lock ,use count : " << wp.use_count() << std::endl;
        std::cout << *sp2 << std::endl;
    }

    // 如果存在双向关联的时候，shared_ptr 由于强引用计数不为0，无法释放，就会出现内存泄漏
    // 这个时候只需要一方设置为 weak_ptr， 其只影响弱引用计数,因此可以打破循环
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    std::cout << "b use count: " << b.use_count() << std::endl;
    std::cout << "a use count: " << a.use_count() << std::endl;
    // a的成员变量point_to_b 是weak_ptr ，因此绑定了b，但是b的强引用计数并没有增加
    a->point_to_b = b;
    b->point_to_a = a;
    std::cout << "b use count: " << b.use_count() << std::endl;
    std::cout << "a use count: " << a.use_count() << std::endl;

    // 到生命周期结束的时候，假设先析构实例a,则先析构a的成员，由于a->point_to_b 是weak_ptr，直接就析构了，然后再次调用a的析构函数，a的引用计数-1
    // 然后析构实例b，b->point_to_a指向实例a，此时a的引用计数为0，这个智能指针就被释放了，然后b也完成析构
    // 都触发析构函数，正确且自动释放内存，打破循环引用
    */

    // 查看源码可知，构造智能指针的时候可以传入一个删除器的参数，这个参数需要式fucntion类的
    std::shared_ptr<FILE> file_ptr(fopen("example.txt", "w"), FileDeleter());
    if (file_ptr)
    {
        std::cout << "file open successfully" << std::endl;
        // 智能指针.get() 方法返回的是裸指针
        fprintf(file_ptr.get(), "hello world");
    }
    return 0;
}

#include <iostream>
#include <cstring>

int main()
{
    /*
    // 数组是一块连续的地址，长度不变，里面存放的每个元素大小相同
    // 数组内可以存放对象，可以存放指针，但是不可以存放引用
    int arr1[10] = {1, 2, 33, 4, 5, 6};

    int *parr1[3];          // 一个存放3个指向int类型的指针 的数组
    int (*ptr)[10] = &arr1; // 一个指向 内部存有10个int类型的数组 的指针

    // 数组名，首个元素的的地址。数组的地址，三者数值上等价，但是类型不同
    // 在这个案例中，&arr1[0]: char* ,   arr1: char[10],   &arr1: char(*)[10]
    std::cout << arr1 << std::endl;
    std::cout << &arr1 << std::endl;
    std::cout << &arr1[0] << std::endl;

    // 不可以用auto类型推断数组的类型,但是可以用 decltype() 推断数组的类型和大小
    decltype(arr1) arr2 = {2, 34, 5};
    std::cout << sizeof(arr2) / sizeof(int) << std::endl;

    // 遍历数组
    // 推荐使用 size_t 类型作为迭代器，它被设计的足够大，可以表示任意对象
    for (size_t i = 0; i < sizeof(arr1) / sizeof(int); i++)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    // 可以用一个指针指向数组尾的下一位
    int *e = arr1 + sizeof(arr1) / sizeof(int);
    for (int *b = arr1; b != e; b++)
    {
        std::cout << *b << " ";
    }
    std::cout << std::endl;

    // c++11之后提供了指向指向数组尾的下一个位置的指针，以及指向首元素的指针
    int *beg = std::begin(arr1);
    int *en = std::end(arr1);
    for (auto it = beg; it != en; it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    */

    // c风格的字符串就是字符数组，结尾是空字符 '\0'
    char cstr1[20] = "hello, ";
    char cstr2[20] = "world";
    std::cout << "size of cstr1: " << sizeof(cstr1) << "      " << "length of cstr1: " << strlen(cstr1) << std::endl;
    {
        strcat(cstr1, cstr2); // 将str2附加到str1，返回str1
        std::cout << "after add:" << cstr1
                  << "      " << "length of after add: "
                  << strlen(cstr1) << std::endl;
    }

    {
        strcpy(cstr1 + strlen(cstr1), cstr2); // 将str2拷贝给str1，返回str1
        std::cout << "after copy :" << cstr1 << "      "
                  << "length of after copy: " << strlen(cstr1) << std::endl;
    }

    {
        const char *cstr1 = "cpp is best";
        std::cout << "cstr1 : " << cstr1 << std::endl;

        // cpp的std::cout 对char* 类型有特殊的重载，当接收到char* 类型的时候，从该地址开始打印字符
        char strarr[20] = {'c', 'p', 'p', 'i', 's', 'b', 'e', 's', 't', '\0'};
        std::cout << "strarr : " << strarr << std::endl;
        char *cstr2 = std::begin(strarr);
        std::cout << "cstr2 : " << cstr2 << std::endl;

        char (*cstr3)[20] = &strarr;
        std::cout << "cstr3 : " << cstr3 << std::endl;
        decltype(&strarr) cstr4 = &strarr;
        std::cout << "cstr4 : " << cstr4 << std::endl;

        // 不能用数组给数组赋值，即使他们类型相同
        // // decltype(strarr) strarr2 = strarr;
        // // std::cout << "strarr2: " << strarr2 << std::endl;

        // 而其他类型则正常打印首地址
        int iarr[10] = {2, 3, 4, 5};
        std::cout << "iarr : " << iarr << std::endl;
    }
    return 0;
}
#include <iostream>
#include <cstring>
#include <cstdlib>

#include "../../inc/memory/memory.h"


int main(){
// C风格的内存管理
// malloc开辟内存，返回值是void*，需要强制转换
// free释放内存
    int* p =(int*) malloc(sizeof(int));
    // 检测是否分配了内存，如果没有分配内存，返回值为空指针
    if(p==NULL){
        std::cerr << "malloc failed" << std::endl;
        return -1;
    }
    *p = 10;
    std::cout << "p = " << *p << std::endl;
    // 释放内存
    free(p);

    // 也可以创建数组
    int* parr = (int*) malloc(sizeof(int)*5);
    for (int i = 0; i < 5; i++){
        parr[i] = i;
    }
    for (int i = 0; i < 5; i++){
        std::cout << "parr[" << i << "] = " << parr[i] ;
    }
    std::cout<<std::endl;
    free(parr);


    //C++风格的内存管理
    // new开辟内存，返回值是指针，不需要强制转换
    int* parray = new int[10]; // 创建一个int类型的数组，大小为10
    delete[] parray;

    //C++风格的开辟和释放内存会调用对象的构造函数和析构函数，而C风格不会
    Student* stu1 = new Student(18,"wtr");
    Student* pstu_arr = new Student[3]{
        {18,"wtr"},
        {19,"wjx"},
        {20,"msy"}
    };

    delete stu1;
    delete [] pstu_arr;
    return 0;
}


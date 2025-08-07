#include <iostream>

int main(){
    //类型别名
    /*
    typedef double twice;
    using uint8_t = char;

    uint8_t a = 'a';
    char b = 'a';
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    */
    //对复合类型起别名，可能有意向不到的后果


    //auto 可以自动推导出变量的类型
    //decltype() 会得到参数的类型
    /*
    int a = 10,&a1 = a;
    decltype(a) b = 20;
    decltype(a1) b1 = b;
    std::cout<<"a="<<a<<','<<"a1="<<a1<<std::endl;
    std::cout<<"b="<<b<<','<<"b1="<<b1<<std::endl;
    */


    return 0;
}
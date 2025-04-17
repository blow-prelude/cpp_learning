#include <iostream>
#include <vector>
#include <algorithm>

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


//指向数组的指针
int array[5]={1,2,3,4,5};
int (*parray)[5]=&array;

// 函数指针
int add(int a,int b){
    return a+b;
}
int (*padd)(int a,int b)= add;

//函数指针可以作为参数，传递给其他函数

int caculate(int(*padd),int c,int d){
    int res = padd(c,d);
}



int main(){

    // int a=add(3,5);
    // double b=add(2.1,5.3);
    // std::cout<<a<<std::endl;   
    // add();

    //lambda函数     
    // 组件：        [捕获列表]（参数列表 ）-> 返回类型可省略{}
    // int sum=0;
    // std::vector numbers = {10,20,30,40};
    // // for_each会生成一个迭代器，对每个元素执行一个一元函数的操作
    // std::for_each(numbers.begin(),numbers.end(),[&sum](int n){
    //     sum+=n;

    // });
    // std::cout<<sum<<std::endl;

    int a = caculate(padd,3,4);
    std::cout<<a<<std::endl;
    return 0;
}
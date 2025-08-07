#include <iostream>

int main(){


    //结构体默认访问权限是public，然而类是private
    struct Student{
        std::string name;
        int age;
        double height;

        //可以封装成员函数
        void print()const{
            std::cout<<name<<' '
            <<age<<' '
            <<height<<std::endl;
        }

        //初始化可以使用c风格的，也可以自定义构造函数
        //在创建对象时会调用构造函数，只不过默认的构造函数是空的，可以重新实现
        //可以在初始化时进行赋值，也可以在函数内部进行赋值
        Student(std::string student_name,int student_age,double student_height)
        :name(student_name),height(student_height){
            age=student_age;
        }
    };

    Student stu1("wtr",18,150.0);
    std::cout<<stu1.age<<std::endl;
    stu1.print();

    //结构体类型也可以定义指向该类型对象的指针
    //结构体指针的元素不能打点调用
    Student* stu2 = &stu1;
    std::cout<<stu2->height<<std::endl;


    return 0;
}
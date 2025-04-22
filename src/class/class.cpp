#include <iostream>
#include <string>
#include "../../inc/class/class.h"

// 在源文件里实现类的成员函数需要  类：：函数名，表示这个函数是属于哪个类的
void Student::setName(std::string name){
        _name = name;
    }

// 构造函数初始化参数可以在初始化列表中实现
// 如果成员变量是引用类型，必须在初始化列表中初始化
Student::Student(std::string name,const std::string &id,int age,std::string& sex)
                :_name(name),_age(age),_id(id),_sex(sex)
{

}

// 拷贝构造函数
Student::Student(const Student& stu)
                :_name(stu._name),_age(stu._age),_id(stu._id),_sex(stu._sex)
{
    // 浅拷贝，指向同一块内存
    //_data = stu._data;
    //注意，调用析构函数会多次释放浅拷贝，导致崩溃

    // 深拷贝，指向不同的内存
    //_data = new int;
    //*_data = *(stu._data);

}

// 移动构造函数
Student::Student(Student&& stu)
:_name(std::move(stu._name)),_age(std::move(stu._age)),_id(std::move(stu._id)),_sex(stu._sex)
{
    // 移动构造的浅拷贝和深拷贝同理
    // int * _data = new int();
    // *_data = std::move(*stu._data);
}


//析构函数
Student::~Student(){
    delete _data;
}


void Undergraduate::getName()const{
            std::cout<<"Undergraduate name is "<<_name<<std::endl;
        }

void Undergraduate::getAge()const{
            std::cout<<"Undergraduate age is "<<_age<<std::endl;
        }   

void Freshman::getAge()const{
    std::cout<<"Freshman age is "<<_age<<std::endl;
}

void Freshman::getName()const{
    std::cout<<"Freshman name is "<<_name<<std::endl;
}

int main(){

    // Student stu1;
    // //对象的public属性可以通过打点调用的形式查看和修改
    // stu1.name = "wtr";
    // stu1.id = "1005";
    // std::cout<<stu1.name<<std::endl;


    // Undergraduate stu1("wtr",18);
    // Freshman stu2("wjx",18,"1006");
    // stu1.getName();
    // stu2.getName();
    //stu2.getAge();

    // 注：getName()是普通的重写，而gerAge*()是虚函数的重写
    
    // 通过基类指针调用派生类的函数,对于普通的重写，基类指针只能调用基类的函数
    Undergraduate* up=new Freshman("wtr",18);
    up->getName();
    Freshman* fp=new Freshman("wtr",18);
    fp->getName();

    // 通过基类指针调用派生类的虚函数，对于虚函数，基类指针可以调用派生类的函数
    up->getAge();
    fp->getAge();




    return 0;
}
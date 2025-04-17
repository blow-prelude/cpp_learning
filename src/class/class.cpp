#include <iostream>
#include <string>
#include "../../inc/class/class.h"

// 在源文件里实现类的成员函数需要  类：：函数名，表示这个函数是属于哪个类的
void Student::setName(std::string name){
        _name = name;
    }

// 构造函数初始化参数可以在初始化列表中实现
// 如果成员变量是引用类型，必须在初始化列表中初始化
Student::Student(std::string name,int age,const std::string &id,std::string& sex)
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


Student::~Student(){
    delete _data;
}

int main(){

    // Student stu1;
    // //对象的public属性可以通过打点调用的形式查看和修改
    // stu1.name = "wtr";
    // stu1.id = "1005";
    // std::cout<<stu1.name<<std::endl;

    return 0;
}
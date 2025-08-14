#include <iostream>
#include <string>
#include <vector>
#include "../inc/class.h"

// 在源文件里实现类的成员函数需要  类：：函数名，表示这个函数是属于哪个类的
void Student::setName(std::string name)
{
    _name = name;
}

// 构造函数初始化参数可以在初始化列表中实现
// 如果成员变量是引用类型，必须在初始化列表中初始化
Student::Student(std::string name, const std::string &id, int age, std::string &sex)
    : _name(name), _age(age), _id(id), _sex(sex)
{
}

// 拷贝构造函数
Student::Student(const Student &stu)
    : _name(stu._name), _age(stu._age), _id(stu._id), _sex(stu._sex)
{
    // 浅拷贝，指向同一块内存
    //_data = stu._data;
    // 注意，调用析构函数会多次释放浅拷贝，导致崩溃

    // 深拷贝，指向不同的内存
    //_data = new int;
    //*_data = *(stu._data);
}

// 拷贝赋值运算符
Student &Student::operator=(const Student &student)
{
    // 先判断是否为自拷贝
    // this是当前对象的指针
    if (this == &student)
    {
        return *this;
    }

    // 对成员变量进行赋值
    this->_name = student._name;
    this->_age = student._age;
    this->_id = student._id;

    // 对于指针类型的成员变量，需要判断原先是否已经分配了内存
    if (_data != nullptr)
    {
        delete _data;
    }
    // 重新分配内存
    _data = new int();
    *_data = *(student._data);
    return *this;
}

// 移动构造函数
Student::Student(Student &&stu)
    : _name(std::move(stu._name)), _age(std::move(stu._age)), _id(std::move(stu._id)), _sex(stu._sex)
{
    // 移动构造的浅拷贝和深拷贝同理
    // int * _data = new int();
    // *_data = std::move(*stu._data);
}
// 移动赋值运算符
Student &Student::operator=(Student &&stu)
{
    // 先判断是否为自拷贝
    if (this == &stu)
    {
        return *this;
    }

    // 对成员变量进行移动
    this->_name = std::move(stu._name);
    this->_age = std::move(stu._age);
    this->_id = std::move(stu._id);

    // 对于指针类型的成员变量，需要判断原先是否已经分配了内存
    if (_data != nullptr)
    {
        delete _data;
    }
    // 重新分配内存
    _data = new int();
    *_data = std::move(*(stu._data));
    return *this;
}

// 析构函数
Student::~Student()
{
    delete _data;
}

Undergraduate::~Undergraduate()
{
    std::cout << "Undergraduate has been delete" << std::endl;
}

Freshman::~Freshman()
{
    std::cout << "Freshman has been delete" << std::endl;
}

void Undergraduate::getName() const
{
    std::cout << "Undergraduate name is " << _name << std::endl;
}

void Undergraduate::getAge() const
{
    std::cout << "Undergraduate age is " << _age << std::endl;
}

void Freshman::getAge() const
{
    std::cout << "Freshman age is " << _age << std::endl;
}

void Freshman::getName() const
{
    std::cout << "Freshman name is " << _name << std::endl;
}

// 友元函数
void knowyourAge(Freshman &freshman)
{
    std::cout << "i am " << freshman._age << std::endl;
}

// 运算符重载之重载+
Freshman &Freshman::operator+(const Freshman &freshman)
{
    // 运算符重载的实现
    this->_age = this->_age + freshman._age;
    return *this;
}

// 运算符重载之重载<<
std::ostream &operator<<(std::ostream &os, const Freshman &freshman)
{
    os << "Freshman name is " << freshman._name << std::endl
       << "Freshman age is " << freshman._age << std::endl;
    return os;
}

int main()
{

    // Student stu1;
    // //对象的public属性可以通过打点调用的形式查看和修改
    // stu1.name = "wtr";
    // stu1.id = "1005";
    // std::cout<<stu1.name<<std::endl;

    // Undergraduate stu1("wtr",18);
    // Freshman stu2("wjx",18,"1006");
    // stu1.getName();
    // stu2.getName();
    // stu2.getAge();

    /*
    // 注：getName()是普通的重写，而getAge*()是虚函数的重写

    // 通过基类指针调用派生类的函数,对于普通的重写，基类指针只能调用基类的函数
    Undergraduate* up=new Freshman("wtr",18);
    up->getName();
    Freshman* fp=new Freshman("wtr",18);
    fp->getName();

    // 通过基类指针调用派生类的虚函数，对于虚函数，基类指针可以调用派生类的函数
    up->getAge();
    fp->getAge();

    // 如果一个基类的指针指向派生类的对象，那么delete该指针时只会调用基类的析构函数。
    // 而由于派生类的内存往往大于基类，就会造成内存泄漏
    // 解决方法是将基类的析构函数声明为虚函数，这样就会调用派生类的析构函数



    // 容器与继承
    // 假设定义了基类的容器，但是向其中添加的是派生类的对象，这时就会发生切片，即派生类的对象会被切片成基类的对象
    // 解决方法是使用指针来存储对象，这样就不会发生切片
    // 但是使用指针或引用时需要注意内存的管理，避免内存泄漏
    std::vector<Undergraduate*> vec;
    vec.push_back(new Freshman("wtr",18));
    vec[0]->getName();
    */

    // 重载运算符 <<,可以直接输出对象
    // Freshman fre1("wtr",18);
    // std::cout<<"freshman is "<<fre1;

    Undergraduate *up = new Freshman("wtr", 18);
    delete up;

    return 0;
}
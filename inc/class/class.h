#include <iostream>
#include <string>
using std::string;

class Student{

    public:
    // 在头文件里，成员函数只做声明，实现在源文件
    void setName(std::string name);

    // getter函数一般用const修饰，表示不会修改类的成员变量
    int getAge()const{
        return _age;
    }


    // 在创建对象的时候会构造函数，构造函数无返回类型，名字和类名相同
    // 在确定某个成员变量不会被修改时，可以使用常量引用类型,可以减小传参时拷贝造成的开销
    Student(std::string name,const std::string& id,int age,std::string& sex);

    //拷贝构造
    //一定要传递引用类型，
    //const是防止对原对象的修改
    Student(const Student& stu);

    //然而有些成员变量不支持拷贝操作，这时就不能有拷贝构造函数
    //移动构造，没有创建拷贝构造，直接把原来的对象传递给新对象，且原对象失效
    //移动构造函数的参数是右值引用类型
    Student(Student&& stu) ;
       

    // 析构函数 也没有参数和返回值
    // 析构函数在对象生命周期结束时自动调用,一般用于结束进程，回收堆上变量等
    ~Student();


    private:
    // 一般把类的成员变量设置为私有，通过成员函数提供接口进行访问或修改
    // 为了区分，类的成员变量一般前置下划线
        std::string _name;
        string _id;
        int _age;

        std::string& _sex;

        // static成员变量属于类本身，而不是某个对象
        // static类型变量不能在构造函数的初始化列表中初始化，需要在非内联文件中初始化，
        //即使他是private类型也可以直接打点调用进行初始化，但是不能访问

        int* _data;

};

//类可以继承
class Freshman:public Student
{
    public:
    //子类可以自己实现构造函数，也可以继承父类已有的构造函数
    Freshman(std::string _name, string _id, int _age, std::string& sex)
        : Student(_name, _id, _age, sex), _name(_name), _id(_id), _age(_age), _sex(sex) {

    }


    private:
        std::string _name;
        string _id;
        int _age;
        std::string& _sex;
};
#include <iostream>
#include <string>
using std::string;

class Student{

    public:
    // 在头文件里，成员函数只做声明，实现在源文件
    void setName(std::string name);

    // getter函数一般用const修饰，表示不会修改类的成员变量
    void getAge()const{
        std::cout<<"age is "<<_age<<std::endl;
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
class Undergraduate{
    public:
        Undergraduate(std::string name,int age)
            :_name(name),_age(age){
                //std::cout<<"Undergraduate constructor"<<std::endl;
        }

        void getName()const;

        virtual void getAge()const;

        //虚函数的特例是纯虚函数
        //纯虚函数必须在子类中实现
        virtual void getSex() = 0; // 纯虚函数，表示这个类是抽象类，不能实例化对象
        //如果一个类有纯虚函数，那么这个类就是抽象类，不能实例化对象
        //抽象类实现了很好的封装性，可以作为接口类，不能直接查看具体实现方法



    protected:
        std::string _name;
        int _age;

};


class Freshman:public Undergraduate
{
    public:
    //子类可以自己实现构造函数，也可以继承父类已有的构造函数
    //如果子类继承了父类的成员变量而不是重新定义，那么子类就只能访问父类的public和protected类型的成员变量  

    //创建对象时，会先调用父类的构造函数，再调用子类的构造函数
    //销毁对象时，会先调用子类的析构函数，再调用父类的析构函数
    Freshman(std::string name, int age)
        : Undergraduate(name,  age){
            //std::cout<<"Freshman constructor"<<std::endl;

    }

    //子类可以直接重写（覆盖）父类的成员函数,重写要求函数名，参数列表，返回值都一致
    void getName()const;

    //虚函数是一种特殊的重写,是实现多态的基础
    //如果父类的成员函数是虚函数，那么子类重写时也要加上virtual关键字
    //为了在编译阶段就能检查出错误，需要在子类的虚函数的声明中加上override关键字
    virtual void getAge()const override;

    virtual void getSex()override
    {
        std::cout<<"i am man"<<std::endl;
    } 


    private:
    //父类中的成员变量，子类无需重复定义
        //std::string _name;
        //string _id;
        //int _age;
        
};
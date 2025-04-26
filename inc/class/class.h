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
    // 一旦定义了构造函数，系统就不会自动创建默认的构造函数了，这时如果还需要默认构造函数，就要自己定义
    // 默认构造函数指的是无需显式传入参数的构造函数
    // 在确定某个成员变量不会被修改时，可以使用常量引用类型,可以减小传参时拷贝造成的开销
    Student(std::string name,const std::string& id,int age,std::string& sex);

    //拷贝构造
    //系统会自动创建一个默认的拷贝构造函数，除非类的成员变量里有引用，const类型，或者是thread这样不可拷贝的类型
    //一定要传递引用类型，这是因为在调用类的拷贝构造时会先对实参进行拷贝，而该过程又会调用拷贝构造函数，以此无限循环
    //const是防止对原对象的修改
    Student(const Student& stu);
    //拷贝赋值运算符，可以重载=，使其可以把一个已有的对象赋值给另一个已有的对象
    //这点与拷贝构造函数不同，拷贝构造函数是创建一个新的对象，而拷贝赋值运算符是把一个已有的对象赋值给另一个已有的对象
    //拷贝赋值运算符的返回值是引用类型，表示可以链式调用
    //Student& 意思是函数返回值类型是Student类对象的引用
    Student& operator=(const Student& stu);
    

    //然而有些成员变量不支持拷贝操作，这时就不能有拷贝构造函数
    //移动构造，没有创建拷贝构造，直接把原来的对象传递给新对象，且原对象失效
    //移动构造函数的参数是右值引用类型
    Student(Student&& stu) ;
    //移动赋值运算符
    Student& operator=(Student&& stu) ;
       

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
        //同样的，静态成员函数也是属于整个类

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

    // 如果子类覆盖了父类的成员函数，可以使用作用域解析符来调用父类的成员函数
    void callParentGetName()
    {
        Undergraduate::getName();
    }   

    //虚函数是一种特殊的重写,是实现多态的基础
    //如果父类的成员函数是虚函数，那么子类重写时也要加上virtual关键字
    //为了在编译阶段就能检查出错误，需要在子类的虚函数的声明中加上override关键字
    virtual void getAge()const override;

    virtual void getSex()override
    {
        std::cout<<"i am man"<<std::endl;
    } 

    //友元函数，不属于该类但是在该类中声明
    friend void knowyourAge(Freshman& freshman); 
    //友元类
    friend class Junior; // 友元类，表示Junior类可以访问Freshman类的私有成员变量

    private:
    //父类中的成员变量，子类无需重复定义
        //std::string _name;
        //string _id;
        //int _age;
        
};


// 访问控制
//如果保护继承父类的，那么父类的public和protected类型的成员变量在子类中都是protected类型的
//同理可得 私有继承
// 为了让编译器知道该类是最后一个继承的类，使用final关键字
class Junior final : private Undergraduate {
    //已经在上文中声明Junior是Freshman的友元，就可以访问Freshman的私有成员变量了
    void knowyourAge(Freshman& freshman) {
        std::cout << "i am " << freshman._age << std::endl;
    }
};


// 派生类的构造函数调用顺序：
// 1. 基类的构造函数
// 2. 派生类的成员对象的构造函数，按照声明顺序依次调用
// 3. 派生类的构造函数



// 友元可以是函数，类，结构体
// 友元可以访问类的私有成员变量
// 友元函数不属于类的成员函数，但是在类中声明


#include <iostream>
#include <string>
#include <sstream>

// iostream里有个std的命名空间，里面有cout等方法，然而并不能直接使用
// 可以using namespace std； 让本文件的命名空间为std。    但是会造成环境的污染

//所以最好对每个名字进行独立的using声明，避免环境的污染，当想使用其他命名空间时可以  ：：  调用
using std::cout;
using std::endl;

int main(){

    /*
    //初始化字符串
    std::string s1 = "hello";
    std::string s2("world");
    // = 会创建一个副本，而不是指向同一个对象
    std::string s11 = s1;
    std::string s22(s2);

    cout<<s11<<','<<s22<<endl;
    s2 = "python";
    cout<<s22<<endl;
    */

    //cout是把字符串输入到屏幕即屏幕流，所以也可以是文件流等等
    //os<<s   ,意思是把s字符串插入os数据流中
    //同理 is>>s

    //字符串可以进行拼接，比大小等操作

    // 对字符串可以进行查找操作，使用find方法，找到了返回索引
    // string text = "you are so good at writing cpp";
    // string word = "cppp";
    // size_t pos = text.find(word);

    // if (pos != string::npos)
    // {
    //     std::cout<<pos<<std::endl;
    //     std::cout<<word<<std::endl;
    // }
    // else
    //     std::cout<<pos<<std::endl;

    // “切片”
    // std::string s1 = "hello world";
    //第一个参数是起始序列，第二个是长度
    // std::string sub1 = s1.substr(1,5);
    // cout<<sub1<<endl;

    //长度和容量
    // cout<<s1.length()<<endl;
    // cout<<s1.capacity()<<endl;

    //字符串和其他类型的数据可以相互转换
    // int a = 10;
    // string a_str = std::to_string(a);
    // std::cout<<a_str<<std::endl;

    // string str1 = "120";
    // int c = std::stoi(str1);
    // std::cout<<c<<std::endl;


    // 也可以从字符串流中读取数据，需要包含sstream头文件
    // string str2 = "123 4.5"
    // std::stringstream ss(str2);
    // int b = 0;
    // double c = 0.0;
    // ss>>b>>c;
    // std::cout<<b<<std::endl;


    // 正则表达式
    
    

    return 0;
}
#include <iostream>
#include <string>
#include <vector>

int main()
{

    // 初始化
    std::vector<int> v1 = {2, 3, 5, 7};
    std::vector<int> v2(5, 10);
    std::vector<int> v3(v2);
    // 可以遍历输出
    // std::cout<<"v1=";
    // c++风格的for循环
    // for (int i:v1){
    //     std::cout<<i<<' ';
    // }
    // std::cout<<std::endl;

    // 也可以使用迭代器
    //  for(auto it=v1.begin();it!=v1.end();it++){
    //      std::cout<<*it<<' ';
    //  }

    // 向量的基本操作   增删改查
    /*
    std::cout<<"origin:";
    for (int i:v2){
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;

    v2.push_back(30);
    std::cout<<"push_back:";
    for (int i:v2){
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;

    v2.pop_back();
    std::cout<<"pop_back:";
    for (int i:v2){
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;

    v2.insert(v2.begin()+1,20);
    std::cout<<"insert:";
    for (int i:v2){
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;

    v2.erase(v2.begin());
    std::cout<<"erase:";
    for (int i:v2){
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;

    //除了下标访问，还可以通过迭代器进行访问
     auto it = v1.end()-1;
    *it = 10;
    for (int i:v1){
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;

   std::vector<std::string> v4 = {"wtr","wjx","msy"};
   std::cout<<v4[1]<<std::endl;
   std::cout<<v4.at(0)<<std::endl;
   std::cout<<std::endl;
   // 异常处理
   try{
        std::cout<<v4.at(10)<<std::endl;
   }catch(std::out_of_range& e){
        std::cerr<<"Exception:"<<e.what()<<std::endl;
   }
    */

    // 由于向量的容量是自动开辟的，会指数型增长，占有内存，所以需要回收
    // 这里让向量与一个空向量进行交换，（把容量，元素全都交换了），然后由于空向量是在块作用域，生命周期只在该块内，所以跳出块后容量被立即释放
    /*
    {
        std::vector<int> empty_v;
        empty_v.swap(v1);

        std::cout<<"capacity of v1:"<<v1.capacity()<<std::endl;
        std::cout<<"capacity of empty_v:"<<empty_v.capacity()<<std::endl;
    }
    */

    // 向量配合复合数据类型风味更佳
    /*
    struct Student{
     std::string id;
     std::string name;
     int age;
    };

    std::vector<Student> stu1;
    stu1.push_back({"1005","wtr",18});
    stu1.push_back({"1006","wjx",19});

    //这里在循环输出时最好使用引用，可以减小开销。  因为如果没有引用的话就会把数据拷贝一份给临时变量stu
    for(auto &stu:stu1){
     std::cout<<stu.id<<' ';
     std::cout<<stu.name<<' ';
     std::cout<<stu.age<<' ';
    }
    std::cout<<std::endl;
    */

    // algorithm里封装了很多算法，如排序,反转,查找，预留空间，收缩容量
    // 可以规定排序规则
    // std::sort(v1.begin(),v1.end());
    // std::reverse(v1.begin(),v1.end());

    return 0;
}
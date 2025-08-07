#include <iostream>
#include <string>
#include <vector>

int main(){
    // 可以用begin,end来遍历容器，其中end指向容器的最后一个元素的下一个位置
    // 注意，string类型不是容器，但是可以用begin和end来遍历

    // 如果容器为空，begin和end是相等的

    // for循环有两种写法
    // std::vector<int> vec = {1,2,3,4,5};
    // for(auto iter = vec.begin(); iter != vec.end(); ++iter){
    //     std::cout<< *iter << std::endl;
    // }
    // std::string s(10,'*');
    // std::cout<< s <<std::endl;
    // 冒号后面是容器，表示变量从该容器中依次取值
    // for(int i : vec){
    //     std::cout<< i << std::endl; 
    // }


    // 迭代器类型，可以auto交给编译器去推导，也可以自己指定
    std::vector<int> vec = {1,2,3,4,5};
    std::vector<std::string> str_vec = {"hello","world"};
    for(std::vector<int> ::iterator iter = vec.begin(); iter != vec.end(); ++iter){
        std::cout<< *iter << std::endl;
    }
    // cbegin和cend是常量迭代器，不能修改容器中的元素
    for(std::vector<std::string> ::const_iterator iter = str_vec.cbegin(); iter != str_vec.cend(); ++iter){
        std::cout<< *iter << std::endl;
    }

    // 修改容器如push_back，insert等操作会使迭代器失效


    // 对容器用迭代器操作时，要判断容器是否为空
    std::string s = "hello world";;
    if (s.begin() == s.end()){
        std::cout<< "string is empty" << std::endl;
    }
    for(auto iter = s.begin(); iter != s.end(); ++iter){
        // 判断是否为空格
        if (isspace (*iter)){
            continue;
        }
        *iter = *iter -32;
    }
    for(auto it : s){
         if (isspace (it)){
            continue;
        }
        std::cout<< it << std::endl;
    }
    


    return 0;
}
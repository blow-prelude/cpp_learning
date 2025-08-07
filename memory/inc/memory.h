#ifndef MOMORY_H
#define MOMORY_H


#include <iostream>
#include <string>
class Student{
public:
    Student(int age, std::string name):_age(age),_name(name){
        std::cout << "Student constructor" << std::endl;
    }
    ~Student(){
        std::cout << "Student destructor" << std::endl;
    }

private:
    int _age;
    std::string _name;

};

#endif 
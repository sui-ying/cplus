#include<iostream>
using namespace std;

#include "../include/demo.h"

// // 类模板
// template<class NameType, class Agetype = int>  // 如果类中有两种数据类型，创建两种数据类型; 告诉编译器Agetype为int
// class Person
// {
// public:
//     NameType Name;
//     Agetype Age;

//     // 模板类构造函数类内声明，类外实现
//     Person(NameType name, Agetype age);
//     // 模板类成员函数类内声明，类外实现
//     void ShowPerson();

// }; 

// // 构造函数类外实现
// template<class NameType, class Agetype>
// Person<NameType, Agetype>::Person(NameType name, Agetype age){
//     this->Name = name;
//     this->Age = age;
// }

// // 成员函数类外实现
// template<class NameType, class Agetype>
// void Person<NameType, Agetype>::ShowPerson(){
//     cout << "Name: " << this->Name << "\t Age: " << this->Age << endl;
// }

void test01()
{
    Person<string, int>p1("momo", 18);
    p1.ShowPerson();
}

int main(){
    test01();
}
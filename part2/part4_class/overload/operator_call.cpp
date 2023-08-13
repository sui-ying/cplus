#include<iostream>
using namespace std;

// 函数调用运算符重载

class Person
{
//    friend ostream & operator<<(ostream &cout, Person &p);
public:
    string Name;
    int Age; 

    // 构造函数使用列表初始化时，需要给形参赋初值
    Person(string name, int age): Name(name), Age(age){};  

    // 1. 使用成员函数进行函数调用运算符符重载
    void operator()(string info){
        cout << info << endl;
    }
};


void test01(){
    Person p1("momo", 18);
    p1("hello !");
}


int main(){
    test01();
}
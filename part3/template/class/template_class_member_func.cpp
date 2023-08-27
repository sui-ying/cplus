#include<iostream>
using namespace std;


class Person1
{
public:
    void ShowPerson1(){
        cout << "call Person1::ShowPerson1()" << endl;
    }
};

class Person2
{
public:
    void ShowPerson2(){
        cout << "call Person1::ShowPerson2()" << endl;
    }
};


template<class T>
class Person
{
public:
    T obj;

    // member function
    void func1(){
        obj.ShowPerson1();
    }

    void func2(){
        obj.ShowPerson2();
    }

};

void test01(){
    Person<Person1> p; // T为Person1类型
    p.func1();
    // p.func2(); // Person1 没有成员函数ShowPerson2； 编译出错，说明函数调用是才会去创建成员函数
}

int main(){
    test01();
}
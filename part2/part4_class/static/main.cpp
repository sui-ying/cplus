#include<iostream>
#include<string>
using namespace std;


// 人类
class Person
{
public:
    int Height;
    static string Name;  // 声明静态成员变量

    static void func(string name="xxx")
    {
        Name = name; // "lolo";     // 静态成员函数可以访问静态成员变量 
        // Height = 170;  // 错误:  静态成员函数不可以访问非静态成员变量
        cout << "调用静态成员函数 static void func()" << endl;
    }

private: 
    static int Age;  // 静态成员变量也有访问权限

    static void PrintItem(){
        cout << "调用私有静态成员函数 static void PrintItem()" << endl;
    }
};

string Person::Name = "momo";
int Person::Age = 18;

void test01(){ 
    // 静态成员变量的两种访问方式
    // 1. 通过对象
    Person p1;
    cout << "p1.Name: " << p1.Name << endl;
    // cout << "p1.Age:  " << p1.Age << endl;  // 静态成员变量也有访问权限，对象不可以访问私有静态成员
    Person p2;
    p2.Name = "nono";
    cout << "p2.Name: " << p2.Name << endl;   // 共享同一份数据
    cout << "p1.Name: " << p1.Name << endl;

    // 2. 通过类名
    cout << "p1.Name: " << Person::Name << endl;

    // 静态成员函数的两种访问方式
    // 1. 通过对象
    p1.func("lolo");
    cout << "p1.Name: " << Person::Name << endl;
    // 2. 通过类名
    Person::func();
}


int main(){
    test01();
}


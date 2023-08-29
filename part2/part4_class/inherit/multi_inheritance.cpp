#include<iostream>
using namespace std;


class Parent1
{
public:
    int A=1;

    Parent1(int a):A(a){
        cout << "调用父类Parent1构造函数" << endl;
    }

    ~Parent1(){
        cout << "调用父类Parent1析构函数" << endl;
    }

    static void func(){
        cout << "Parent static void func()" << endl;
    }

};


class Parent2
{
public:
    int B=1;

    Parent2(int b):B(b){
        cout << "调用父类Parent2构造函数" << endl;
    }

    ~Parent2(){
        cout << "调用父类Parent2析构函数" << endl;
    }

    static void func(){
        cout << "Parent static void func()" << endl;
    }

};


// 共有继承
class Son1: public Parent1, public Parent2
{
public:
    int C;

    void PrintInfo(){
        cout << "Son1 inherited from Parent1 && Parent2" << endl;
        cout << "A: " << A << endl;  // 父类中的公共权限成员 到子类中依然是公共权限
        cout << "B: " << B << endl;  // 父类中的保护权限成员 到子类中依然是保护权限
        cout << "C: " << C << endl; 
    }

    Son1(int a, int b, int c) : Parent1(a), Parent2(b), C(c)
    {
        cout << "调用子类Son1构造函数" << endl;
    }

    ~Son1(){
        cout << "调用子类Son1析构函数" << endl;
    }

};


void test01(){
    Son1 s1(1, 2, 3);
    s1.PrintInfo();

    cout << "sizeof(s1): " << sizeof(s1) << endl;  // 3个整型变量 * 4字节

    // 通过子类对象访问父类中同名成员， 需要加作用域
    cout << "s1.Parent1::A: " << s1.Parent1::A << endl;
    cout << "s1.Parent2::B: " << s1.Parent2::B << endl;
    cout << "s1.C: " << s1.C << endl;

    // 也可以通过类名访问
}

int main(){
    test01();
    // test02();
    // test03();
}
#include<iostream>
using namespace std;


class Parent
{
public:
    int A=1;
    static int D;  // 静态成员，类内声明，类外初始化

    Parent(int a, int b, int c):A(a), B(b), C(c){
        cout << "调用父类Parent构造函数" << endl;
    }

    ~Parent(){
        cout << "调用父类Parent析构函数" << endl;
    }

    void PrintInfo(){
        cout << "PrintInfo Parent" << endl;
        cout << "A: " << A << endl;  
        cout << "B: " << B << endl;  
        cout << "C: " << C << endl; 
    }

    void PrintInfo(int a){
        cout << "PrintInfo Parent(int a)" << endl;
    }

    static void func(){
        cout << "Parent static void func()" << endl;
    }

protected:
    int B=2;


private:
    int C=3;

};
int Parent::D = 10;  // 静态成员，类内声明，类外初始化


// 共有继承
class Son1: public Parent
{
public:
    int A;
    static int D;  // 静态成员，类内声明，类外初始化

    void PrintInfo(){
        cout << "Son1 inherited from Parent" << endl;
        cout << "A: " << A << endl;  // 父类中的公共权限成员 到子类中依然是公共权限
        cout << "B: " << B << endl;  // 父类中的保护权限成员 到子类中依然是保护权限
        // cout << "C: " << C << endl; // 父类中的私有权限成员 子类中访问不到
        cout << "D: " << D << endl;
    }

    Son1(int a, int b, int c) : Parent(a, b, c), A(a)
    {
        cout << "调用子类Son1构造函数" << endl;
    }

    ~Son1(){
        cout << "调用子类Son1析构函数" << endl;
    }

    static void func(){
        cout << "Son1 static void func()" << endl;
    }
};
int Son1::D = 10;  // 静态成员，类内声明，类外初始化


void test01(){
    Son1 s1(1, 2, 3);

    cout << "继承中同成员的处理"<< endl;
    cout << "s1.A: " << s1.A << endl;
    // 通过子类对象访问父类中同名成员， 需要加作用域
    cout << "s1.Parent::A: " << s1.Parent::A << endl;
}


void test02(){
    Son1 s1(1, 2, 3);

    cout << "继承中同成员函数的处理"<< endl;
    s1.PrintInfo();
    // 通过子类对象访问父类中同名成员， 需要加作用域
    s1.Parent::PrintInfo(100);
}


void test03(){
    Son1 s1(1, 2, 3);

    cout << "继承中同静态成员的处理"<< endl;
    cout << "s1.D: "<< s1.D << endl;  // 通过对象访问
    cout << "s1.Parent::D: " << s1.Parent::D << endl;  // 通过对象访问

    cout << "Son1::D: "<< Son1::D << endl;  // 通过类名访问
    cout << "Son1::Parent::D: " << Son1::Parent::D << endl;  // 通过类名访问


    cout << "继承中同静态成员函数的处理"<< endl;
    s1.func();
    s1.Parent::func();
    
    Son1::func();  // 通过类名访问
    Son1::Parent::func();
}

int main(){
    // test01();
    // test02();
    test03();
}
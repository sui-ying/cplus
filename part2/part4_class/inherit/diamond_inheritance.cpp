#include<iostream>
using namespace std;


class Parent1
{
public:
    int A;

    Parent1(int a): A(a){
        cout << "调用父类Parent1构造函数" << endl;
    }

    ~Parent1(){
        cout << "调用父类Parent1析构函数" << endl;
    }

    static void func(){
        cout << "Parent static void func()" << endl;
    }
};

class Son1: virtual public Parent1  // 使用虚拟继承vitrual
{
public:
    void PrintInfo(){
        cout << "Son1 inherited from Parent1" << endl;
        cout << "A: " << A << endl;
    }

    Son1(int a) : Parent1(a) {
        cout << "调用子类Son1构造函数" << endl;
    }

    ~Son1(){
        cout << "调用子类Son1析构函数" << endl;
    }
};

class Son2: virtual public Parent1  // 使用虚拟继承
{
public:
    void PrintInfo(){
        cout << "Son2 inherited from Parent1" << endl;
        cout << "A: " << A << endl;
    }

    Son2(int a) : Parent1(a) {
        cout << "调用子类Son2构造函数" << endl;
    }

    ~Son2(){
        cout << "调用子类Son2析构函数" << endl;
    }
};

class GrandSon: public Son1, public Son2
{
public:
    GrandSon(int a) : Parent1(a), Son1(a), Son2(a) {  // 在构造函数中显式调用基类的构造函数
        cout << "调用子类GrandSon构造函数" << endl;
    }

    ~GrandSon(){
        cout << "调用子类GrandSon析构函数" << endl;
    }
};

void test01(){
    GrandSon g1(1);
    cout << "g1.Son1::A: " << g1.Son1::A << endl;
    cout << "g1.Son2::Parent1::A " << g1.Son2::Parent1::A << endl;

    // 如果两个父类拥有相同的数据，需要加作用域区分
    g1.Son1::A = 2;
    cout << "g1.Son1::A: " << g1.Son1::A << endl;
    cout << "g1.Son1::Parent1::A " << g1.Son2::Parent1::A << endl;
    g1.Son2::A = 3;
    cout << "g1.Son2::A: " << g1.Son2::A << endl;
    cout << "g1.Son2::Parent1::A " << g1.Son2::Parent1::A << endl;

}

int main(){
    test01();
}

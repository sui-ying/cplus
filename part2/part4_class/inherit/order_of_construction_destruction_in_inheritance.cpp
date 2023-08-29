#include<iostream>
using namespace std;


class Parent
{
public:
    int A=1;

    Parent(int a, int b, int c):A(a), B(b), C(c){
        cout << "调用父类Parent构造函数" << endl;
    }

    ~Parent(){
        cout << "调用父类Parent析构函数" << endl;
    }


protected:
    int B=2;


private:
    int C=3;

};

// 共有继承
class Son1: public Parent
{
public:
    int D;
    Son1(int a, int b, int c, int d) : Parent(a, b, c), D(d)
    {
        cout << "调用子类Son1构造函数" << endl;
    }

    ~Son1(){
        cout << "调用子类Son1析构函数" << endl;
    }
};

void test01(){
    Son1 s1(1, 2, 3, 4);
}


int main(){
    test01();
}
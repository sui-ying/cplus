#include<iostream>
using namespace std;


class Parent
{
public:
    int A=1;


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

    void PrintInfo(){
        cout << "Son1 inherited from Parent" << endl;
        cout << "A: " << A << endl;  // 父类中的公共权限成员 到子类中依然是公共权限
        cout << "B: " << B << endl;  // 父类中的保护权限成员 到子类中依然是保护权限
        // cout << "C: " << C << endl; // 父类中的私有权限成员 子类中访问不到
    }
};


class Son2: protected Parent
{
public:
    void PrintInfo(){
        cout << "Son2 inherited from Parent" << endl;
        cout << "A: " << A << endl;  // 父类中的公共权限成员 到子类中是保护权限
        cout << "B: " << B << endl;  // 父类中的保护权限成员 到子类中是保护权限
        // cout << "C: " << C << endl;   // 父类中的私有权限成员 子类中访问不到
    }
};


class Son3: private Parent
{
public:
    void PrintInfo(){
        cout << "Son3 inherited from Parent" << endl;
        cout << "A: " << A << endl;  // 父类中的公共权限成员 到子类中是私有权限
        cout << "B: " << B << endl;  // 父类中的保护权限成员 到子类中是私有权限
        // cout << "C: " << C << endl;  // 父类中的私有权限成员 子类中访问不到
    }
};

class GrandSon3: public Son3
{
public:
    // A = 10;  // 父类中的私有权限成员 子类中访问不到
    // B = 20;
    // C = 30;
};

void test(){
    Son1 son1;
    son1.A = 10;
    // son1.B = 10;   // 保护权限，在类外不可访问
    son1.PrintInfo();

    cout << "sizeof(son1): " << sizeof(son1) << endl;  // 占用16个字节， 4个整型变量

    Son2 son2;
    // son2.A = 20;  // 保护权限，在类外不可访问
    // son2.B = 10;  // 保护权限，在类外不可访问
    son2.PrintInfo();

    Son3 son3;
    // son3.A = 20;  // 私有权限，在类外不可访问
    // son3.B = 10;  // 私有权限，在类外不可访问
    son3.PrintInfo();
}

int main(){
    test();
}
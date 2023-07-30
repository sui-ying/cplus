#include<iostream>

using namespace std;

// 函数重载, 可以简化代码量，但是满足:
// 1. 同一个作用域
// 2. 函数名称相同
// 3. 函数参数类型不同，或者函数个数不同，或者函数形参顺序不同
// 4. 注意: 函数的返回类型不同不可以作为函数重载的条件

void func(){
    cout << "This is func()" << endl;
}

void func(int a){
    cout << "This is func(int a)" << endl;
}

void func(double a){
    cout << "This is func(double a)" << endl;
}

void func(double b, int a){
    cout << "This is func(double b, int a)" << endl;
}

void func(int a, double b){
    cout << "This is func(int a, double b)" << endl;
}

// ********************************************************
// 函数重载的注意事项：
// 1. 应用作为重载的条件
// 2. 碰到默认参数，避免二义性； 重载尽量不用默认参数
void ref(int &ref){
    cout << "This is ref(int &ref)" << endl;
}

void ref(const int &ref){
    cout << "This is ref(const int &ref)" << endl;
}

void func2(int a=10){
    cout << "This is func2(int a=10)" << endl;
}

void func2(int a, int b = 10){
    cout << "This is func2(int a, int b = 10)" << endl;
}


int main(){

    int a = 10;
    double b = 20;
    func();
    func(a);
    func(b);
    func(a, b);
    func(b, a);

    // *****************************************************
    ref(a);  // a是一个变量
    ref(10);

    // func2(10); // 重载尽量不用默认参数
}
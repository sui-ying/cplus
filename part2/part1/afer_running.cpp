#include<iostream>

using namespace std;

int * func(){
    int a = 10;  // 局部变量: 存放在栈区，栈区的数据在函数执行后自动释放
    cout << "&a: " << &a << endl;
    return &a; //[错误示范]不要返回返回局部变量的地址
}


void * func1(){
    // 用关键字new, 可以将数据开辟到栈区; 返回的是该数据类型的指针
    // 指针本质也是局部变量，放到栈上，指针保存的数据是放在堆区
    int *p = new int(10); // 创建一个变量
    delete p; // 用关键字delete释放
}


void * func2(){
    int *arr = new int[10]; // 创建一个数组，长度为10
    for (int i=0; i<10; i++){
        arr[i] = i;
        cout << "arr[i]: " << arr[i] << endl;
    }
    delete[] arr; // 释放堆区数组: delete[]
}


int main(){
    int *p = func();
    cout << "p: " << p << endl;
    // cout << "*p: " << *p << endl;

    func2();
}
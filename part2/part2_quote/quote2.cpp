#include<iostream>

using namespace std;

// 引用的本质: *指针常量*
/**
 * @brief 发现为引用, 转换为int * const ref = &a;
 * @param ref 
 */
void func(int &ref){
    ref = 100;
}


int main(){
    int a = 10;
    int &ref = a;  // 等价于初始化指针常量 int * const ref = &a; 指向地址不可以更改，但是内容可以更改
    cout << "a: " << a << endl;
    cout << "ref: " << ref << endl;

    ref = 20;  // 等价于 *ref=20; 改变地址的内容
    cout << "a: " << a << endl;  
    cout << "ref: " << ref << endl;

    func(a);  // 函数调用
    cout << "a: " << a << endl;
    cout << "ref: " << ref << endl;
}
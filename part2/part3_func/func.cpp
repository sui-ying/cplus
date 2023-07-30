#include<iostream>

using namespace std;

/**
 * @brief 类似python函数；
 * 对于函数默认参数，如果我们传入了自己的数据，就会改变默认值；否则使用默认值
 * 默认参数从左到右必须有默认参数
 * 另外，声明和函数实现只能有一个有默认参数
 * @param a 
 * @param b 
 * @param c 
 * @return int 
 */
int func(int a, int b=20, int c=30){
    return a+b+c;
}

/**
 * @brief 占位参数: 只写了数据类型，函数调用时必须传入同类型数据
 * @param a 
 */
void func1(int a, int){
    cout << "This is placeholder function" << endl;
}


int main(){
    cout << func(10) << endl;

    func1(10, 20); // 调用时必须必须传入同类型数据
}
#include<iostream>
#include<string>
using namespace std;


// 运算符
int main(){
    
    /* 加减乘除 */
    int a = 10;
    int b = 3;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl; 

    /* 
    前置递增: 先递增, 在计算表达式
    后置递增: 先计算，后递增
    */
    cout << "++a: " << ++a << endl;
    cout << "a: " << a << endl;
    cout << "b++: " << b++ << endl;
    cout << "b: " << b << endl;

    /* 
    取模运算 % 
        基于除法运算, 除数不能为0
        只有整型变量可以进行取模运算符
    */
    cout << "a % b = " << a % b << endl;

    /* 
    赋值运算符
        =
        +=
        -=
        *=
        /=
        %=
    */
    a += 1;
    cout << "a: " << a << endl;


    /* 
    比较运算符
        ==
        !=
        <
        >
        >=
        <=
    */
    cout << "a == b :" << (a == b) << endl;  // 1: true; 0: false


    /* 
    逻辑运算符
        &&  逻辑与
        ||  逻辑或
        !   逻辑非

    */
    cout << "a && b :" << (a && b) << endl;  // 1: true; 0: false

}
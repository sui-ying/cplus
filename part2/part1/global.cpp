#include<iostream>

using namespace std;

/*
    全局中的数据: 全局变量、const修饰的全局变量、常量、static
    常量区中存放的全局常量和字符串常量
*/

// 全局变量
int g_a = 10;
int g_b = 20;

// const修饰的全局变量
const int c_g_a = 10;
const int c_g_b = 20;

int main(){
    int a = 10;
    int b = 20;
    cout << "local variable a : " << (int*)&a << endl;  // 局部变量的地址
    cout << "local variable b : " << (int*)&b << endl;  // 局部变量的地址

    cout << "string variable: " << (int*)&"hello world" << endl;  //字符串常量的地址
    
    cout << "global variable g_a: " << (int*)&g_a << endl;  // 全局变量的地址
    cout << "global variable g_b: " << (int*)&g_b << endl;  // 全局变量的地址

    static int s_a = 10;
    static int s_b = 20;
    cout << "static variable s_a: " << (int*)&s_a << endl;  // 静态变量的地址
    cout << "static variable s_b: " << (int*)&s_b << endl;  // 静态变量的地址


    // const修饰的全局变量
    cout << "const global variable c_g_a: " << (int*)&c_g_a << endl;
    cout << "const global variable c_g_b: " << (int*)&c_g_b << endl;

    // const修饰的局部变量
    const int c_l_a = 10;
    const int c_l_b = 20;
    cout << "const local variable c_l_a: " << (int*)&c_l_a << endl;
    cout << "const local variable c_l_b: " << (int*)&c_l_b << endl;

}
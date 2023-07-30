#include<iostream>

using namespace std;


/*
    引用: 给变量起别名
*/

/**
 * @brief 
 * @param a 
 * @param b 
 */
void swap1(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}  

/**
 * @brief 
 * @param p1 
 * @param p2 
 */
void swap2(int *p1, int *p2){
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

/**
 * @brief 
 * @param a 
 * @param b 
 */
void swap3(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}


int main(){
    int a = 10;
    
    // 定义: 数据类型 &别名 = 原名
    int &b = a; // 引用必须初始化，之后不可以改变
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    b=100;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    int c = 10;
    // int &b = c; // 
    
    
    int a1 = 10;
    int b1 = 20;
    swap1(a1, b1);  // 值作为新参: 不变化
    cout << "a1: " << a1 << " b1: " << b1 << endl;

    swap2(&a1, &b1); //地址作为形参: 交换变化
    cout << "a1: " << a1 << " b1: " << b1 << endl;

    swap3(a1, b1);  // 引用作为形参: 交换也变化
    cout << "a1: " << a1 << " b1: " << b1 << endl;
}   
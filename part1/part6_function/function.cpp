#include<iostream>
#include<string>

#include "function.h"

using namespace std;

/*
函数格式
    *************************************************
    返回类型 函数名(形参1, 形参2, ...){
        函数体;
        return 表达式;
    }
    *************************************************
    
注:
    1. 如果不需要返回值时，`返回类型` 可以写void
    2. 无参无返、无参有返、有参有返、有参无返

函数声名: 
    函数声名可以写多次，但是函数定义只能写一次
    函数声名可以放在.h文件中?

函数分文件编写:
    1. 创建后缀为.h的头文件
    2. 创建后缀为.cpp的源文件
    3. 在头文件中写函数声名
    4. 在源文件中写函数的定义
*/

int sums(int arr[]){
    // 一维数组求和
    int sum = 0;
    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        sum += arr[i];
    }
    return sum;
}

/**
 * @brief 两数交换，不改变实参
 * @param num1 数字1
 * @param num2 数字2
 */
void swap(int num1, int num2){
    cout << &num1 << " " << &num2 << endl;
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
    cout << &num1 << " " << &num2 << endl;

}

int main(){
    int score[5] = {95, 85, 75}; 
    int scores = sums(score);
    cout << "scores: " << scores << endl;

    int a=1;  // 实参
    int b=2;
    cout << &a << " " << &b << endl;
    swap(a, b);  // 值传递时，函数的形参反生变化时，并不会影响实参
    cout << "a: " << a << " b: " << b << endl;

}
    
#include<iostream>
using namespace std;

/*
    常量: 用于记录程序中不可更改的数据；定义方式有两种，如下: 
        1. define 宏常量
        2. const 修饰的变量
*/

#define WeekDay 7

/*
    多行注释:
    main是一个程序的入口，每个程序都有一个这样的函数，每个函数有且只有一个main函数
*/
int main(){

    /* 
        变量存在的意义: 便于管理内存空间
        创建变量的语法: 数据类型 变量名 = 变量初始值
        变量名命令规则:
            1.不可以为关键字
            2.标识符第一个字符只能是字母或者下划线
            3.标识符第一个字符只能是字母或者下划线
            4.标识符区分大小写
            5.命名时，尽量做到见名知意
    */
    int a=1;
    cout << "a: " << a << endl;
    
    //单行注释: 打印常量WeekDay
    cout << "WeekDay: " << WeekDay << endl; 

    // const 修饰的变量
    const int month = 12;
    cout << "month: " << month << endl; 

    return 0;
}
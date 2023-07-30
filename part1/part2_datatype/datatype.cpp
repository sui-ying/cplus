#include<iostream>
#include<string>
using namespace std;


int main(){

    /******************** 1. int 整型********************/
    // 1.1 短整型 short（-32768~32677）
    short int num1 = 587678696;  // overflow
    cout << "num1: " << num1 << endl;
    // sizeof() 打印数据类型或者变量所占用的内存空间
    cout << "short sizeof: " << sizeof(short) << endl;
    
    // 1.2 整形 int ()
    cout << "int sizeof: " << sizeof(int) << endl;

    // 1.3 long
    cout << "long sizeof: " << sizeof(long) << endl;

    // 1.4 long long
    cout << "long long sizeof: " << sizeof(long long) << endl;

    /******************** 2. float & double 浮点型********************/
    cout << "float sizeof: " << sizeof(float) << endl;

    cout << "double sizeof: " << sizeof(double) << endl;

    /******************** 3. char 字符型********************/
    /*
        创建方式: 单引号创建
        所占内存
        常见错误
        对应的ASCII编码
    */
    char ch = 'a';  // 单引号创建, 不能使用双引号
    cout << "char sizeof: " << sizeof(ch) << endl;


    /******************** 4. 转义字符 ********************/
    cout << "char sizeof: \n" << endl;  //换行符


    /******************** 5. string 字符串 ********************/
    /*
        C 风格字符串
        C++ 风格字符串
    */
    char str[] = "hello world";  // C 风格字符串
    string str2 = "hello world";  // C++ 风格字符串, 双引号; 需要包含 #include<string>


    /******************** 6. 布尔 ********************/
    /*
        创建方式: 
        所占内存
    */
    bool flag = true;
    cout << "bool sizeof: " << sizeof(flag) << endl;


    /* 
    数据的输入
    */
    int a;
    cout << "请给整型变量赋值: " << endl;
    cin >> a;
    cout << "a: " << a << endl; 
    
}

#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>  // 标准算法头文件

/**
 * @brief string 构造函数
   string(); 创建一个空的字符串
   string(const char* s); 使用C风格字符串s初始化
   string(const string & str);  使用一个string对象初始化另一个string对象
   string(int n, char c);  使用n个字符从初始化
 */
void test01(){
    string s1;  // 默认构造函数
    cout << "s1: " << s1 << endl;
    
    const char * str = "hello world";
    string s2(str);  //使用C风格字符串s初始化
    cout << "s2: " << s2 << endl;

    string s3(s2);  // 使用一个string对象初始化另一个string对象
    cout << "s3: " << s3 << endl;

    // string s4(3, "a");
    string s4(3, 'a');  // 使用n个字符从初始化
    cout << "s4: " << s4 << endl;

}

/**
 * @brief 
 * string & operator=(const char* s);       // char* 类型字符串赋值给当前的字符串
 * string & operator=(const string &s);     // 把字符串s赋给当前的字符串
 * string & operator=(char c);              // 把字符赋值给当前的字符串
 * string & assign(const char *s);          // 把字符串s赋值给当前的字符串
 * string & assign(const char *s, int n);   // 把字符串s的前n个字符赋值给当前的字符串
 * string & assign(const string &s);        // 把字符串s赋值给当前的字符串
 * string & assign(int n, char c);          // 用n个字符C 赋给当前字符串
 */
void test02(){
    string s1;
    s1 = "hello world";
    cout << "s1: " << s1 << endl;

    string s2;
    s2 = s1;
    cout << "s2: " << s2 << endl;

    string s3;
    s3 = 'h';
    cout << "s3: " << s3 << endl;

    string s4;
    s4.assign("hello world");
    cout << "s4: " << s4 << endl;

    string s5;
    // s5.assign('hello world', 6);
    s5.assign("hello world", 7);
    cout << "s5: " << s5 << endl;

    string s6;
    // s5.assign('hello world', 6);
    s6.assign(s5);
    cout << "s6: " << s6 << endl;

    string s7;
    // s5.assign('hello world', 6);
    s7.assign(3, 'h');
    cout << "s7: " << s7 << endl;

}

int main(){
    test01();  // 熟悉string 构造函数
    test02();  // 熟悉string 赋值操作
}
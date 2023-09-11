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
 * @brief 字符串赋值
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
    s3 = 'h';   // 把字符赋值给当前的字符串
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

/**
 * @brief 字符串拼接
 * string& operator+=(const char* str);    // 重载+=运算符
 * string& operator+=(const char c);       // 重载+=运算符
 * string& operator+=(const string& s);    // 重载+=运算符
 * string& append(const char *s);          // 把字符串s连接到当前字符串结尾
 * string& append(const char *s， int n);  // 把字符串s的前n个字符连接到当前字符串结尾
 * string& append(const string& s);        // 同operator+=(const char* str)
 * string& append(const string& s， int pos, int n);         // 把字符串s从pos开始的第n个字符连接到当前字符串结尾
 */
void test03(){
    string s1 = " hello";
    s1 += " world";
    cout << "s1: " << s1 << endl;

    string s2;
    s2 = '!';
    s1 += s2;
    cout << "s1: " << s1 << endl;

    string s3 = "I";
    s3.append(" Love ");
    cout << "s3: " << s3 << endl;

    s3.append("momonono", 4);
    cout << "s3: " << s3 << endl;

    s3.append(s1);
    cout << "s3: " << s3 << endl;

    s3.append(s1, 7, 12);  
    cout << "s3: " << s3 << endl;
}

/**
 * @brief 字符串查找和替换
 * 
 */
void test04(){
    string s1 = "abcdef";
    int pos = s1.find("de");  // 从左往右查找

    if (pos == -1){
        cout << "s1 dont has 'de'" << endl;
    }
    else{
        cout << "pos: " << pos << endl;  // 从0开始
    }

    int pos2 = s1.rfind("de");  // 从右往左查找
    if (pos2 == -1){
        cout << "s1 dont has 'de'" << endl;
    }
    else{
        cout << "pos2: " << pos2 << endl;  
    }

    s1.replace(1, 3, "11");  // s1的第1个到第3个字符替换为11
    cout << "s1: " << s1 << endl;
}

/**
 * @brief 字符串比较ASCAII，类似python
 * 
 */
void test05(){
    string s1 = "hello world";
    string s2 = "hello world";
    if (s1.compare(s2) == 0){
        cout << "s1 == s2" << endl;
    }
    else if (s1.compare(s2) > 0){
        cout << "s1 > s2" << endl;
    }
    else if (s1.compare(s2) > 0){
        cout << "s1 < s2" << endl;
    }
}

/**
 * @brief 字符存取
 * 
 */
void test06(){
    string s1 = "hello";
    // 通过[]访问字符串中的字符
    for (int i=0; i<s1.size(); i++){
        cout << s1[i] << " ";
    }
    cout << endl;

    // 通过string.at()访问字符串中的字符
    for (int i=0; i<s1.size(); i++){
        cout << s1.at(i) << " ";
    }
    cout << endl;

    // 修改字符串中的字符
    s1[0] = 'H';
    cout << "s1: " << s1 << endl;


}

void test07(){
    string s1 = "hello";

    // insert
    s1.insert(1, "111");  //在第一个位置插入 111
    cout << "s1: " << s1 << endl;

    // erase
    s1.erase(1, 3);  //从第一个位置开始删除三个字符
    cout << "s1: " << s1 << endl;

}

int main(){
    // test01();  // 熟悉string 构造函数
    // test02();  // 熟悉string 赋值操作
    // test03();  // 熟悉string 拼接操作
    // test04();  // 熟悉string 查找和替换
    // test05();  // 熟悉string 比较
    // test06();     // 熟悉string 访问和修改其中的字符
    test07();     // 熟悉string 插入和删除
}